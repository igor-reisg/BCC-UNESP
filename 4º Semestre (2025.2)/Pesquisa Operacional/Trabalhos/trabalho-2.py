"""
Trabalho 1 - Método Simplex - Pesquisa Operacional
Aluno: Igor dos Reis Gomes
RA: 241025265
"""

import numpy as np
import sys

np.set_printoptions(precision=4, suppress=True, linewidth=150)

class SimplexDuasFases:
    """
    Implementação do Método Simplex de Duas Fases para problemas de Minimização
    """
    
    def __init__(self, c, A, b):
        """
        Inicializa o solver.
        Assume o problema na Forma Padrão de Minimização:
        Minimizar Z = c^T * x
        Sujeito a: Ax = b
                   x >= 0
        """
        # Convertendo para arrays numpy float para precisão decimal
        self.c = np.array(c, dtype=float)
        self.A = np.array(A, dtype=float)
        self.b = np.array(b, dtype=float)
        
        self.m, self.n = self.A.shape  # m = restrições, n = variáveis originais
        self.status = "Não Iniciado"
        self.solucao = None
        self.valor_otimo = None
        
        # Tolerância para evitar erros de ponto flutuante
        self.tol = 1e-9

    def resolver(self):
        """
        Executa o método de Duas Fases completo
        """
        print("\n" + "=" * 60)
        print("INICIANDO MÉTODO SIMPLEX DE DUAS FASES")
        print("="*60)

        # --- FASE I ---
        # Objetivo: Minimizar w = soma das variáveis artificiais
        print("\n--- FASE I: Encontrar Solução Básica Viável Inicial ---")
        
        # Criar matriz Identidade para as variáveis artificiais (I_a)
        identidade_artificiais = np.eye(self.m)
        
        # Construção do Tableau Inicial da Fase I
        # Dimensões: (m restrições + 1 linha W + 1 linha Z) x (n originais + m artificiais + 1 coluna b)
        num_linhas_total = self.m + 2
        num_colunas_total = self.n + self.m + 1
        
        quadro = np.zeros((num_linhas_total, num_colunas_total))
        
        # Preenchendo a matriz A (variáveis originais) e Identidade (artificiais)
        quadro[:self.m, :self.n] = self.A
        quadro[:self.m, self.n:self.n+self.m] = identidade_artificiais
        quadro[:self.m, -1] = self.b
        
        # Preenchendo a linha Z (penúltima linha, índice m) - apenas carrega os custos originais
        quadro[self.m+1, :self.n] = self.c
        
        # Preenchendo a linha W (antepenúltima linha, índice m) - Função objetivo da Fase I
        # Inicialmente, w = Soma(x_artificial). Para zerar os custos reduzidos das bases artificiais,
        # subtraí as linhas das restrições da linha da função objetivo W.
        # No quadro inicial: Linha W = -Soma(Linhas das restrições)
        for j in range(num_colunas_total):
            if j < self.n: # Variáveis originais
                quadro[self.m, j] = -np.sum(quadro[:self.m, j])
            elif j >= self.n and j < self.n + self.m: # Variáveis artificiais (são básicas)
                quadro[self.m, j] = 0
            else: # Coluna b (lado direito)
                quadro[self.m, j] = -np.sum(quadro[:self.m, j])

        self.imprimir_quadro(quadro, fase=1)

        # Executa Simplex para Fase I (Minimizando w)
        # O alvo é a função w
        quadro, status_w = self.executar_iteracoes_simplex(quadro, indice_linha_alvo=self.m, fase=1)

        if status_w == "Ilimitado":
            print("Fase I ilimitada (impossível pois w >= 0).")
            return

        # Verificar se o valor ótimo de w é 0
        valor_w = -quadro[self.m, -1]
        
        if valor_w > self.tol:
            self.status = "Inviável"
            print(f"\nPROBLEMA INVIÁVEL: Valor mínimo de w = {valor_w:.4f} > 0.")
            print("Não foi possível eliminar todas as variáveis artificiais")
            return
        
        print("\nFase I concluída com sucesso (w = 0). Passando para Fase II.")
        
        # --- FASE II ---
        # Minimizar Z original usando a base encontrada
        print("\n--- FASE II: Otimizar Função Objetivo Original ---")
        
        # Remove colunas das variáveis artificiais
        # As colunas artificiais estão entre os índices n e n+m
        quadro_fase2 = np.delete(quadro, slice(self.n, self.n + self.m), axis=1)
        
        # Remove a linha da função w (que era a linha de índice m)
        quadro_fase2 = np.delete(quadro_fase2, self.m, axis=0)
        
        # Agora a linha Z (que era m+1) passa a ser a última linha (índice m)
        self.imprimir_quadro(quadro_fase2, fase=2)
        
        # Executa Simplex para Fase II (Minimizando Z)
        # O objetivo agora é a última linha
        quadro_final, status_z = self.executar_iteracoes_simplex(quadro_fase2, indice_linha_alvo=self.m, fase=2)
        
        self.status = status_z
        
        if self.status == "Otimo" or self.status == "Ótimo":
            self.extrair_solucao(quadro_final)
            self.verificar_multiplas_solucoes(quadro_final)
            
    def executar_iteracoes_simplex(self, quadro, indice_linha_alvo, fase):
        """
        Loop principal das iterações do Simplex (Pivoteamento).
        Controla a entrada e saída de variáveis na base
        """
        i = 1
        while True:
            # 1. Teste de Otimalidade: Procurar custo reduzido mais negativo (Minimização)
            # Ignora a última coluna (b)
            custos_reduzidos = quadro[indice_linha_alvo, :-1]
            custo_minimo = np.min(custos_reduzidos)
            
            # Se todos custos reduzidos >= 0, para
            if custo_minimo >= -self.tol:
                return quadro, "Ótimo"
            
            # Escolha da variável de entrada
            # Em caso de empate, pega o menor índice
            candidatos_entrada = np.where(np.abs(custos_reduzidos - custo_minimo) < self.tol)[0]
            coluna_entrada = candidatos_entrada[0] 
            
            # 2. Teste da Razão Mínima (Variável de saída)
            razoes = []
            
            # Número de linhas de restrição (exclui linhas de função objetivo)
            num_linhas_restricoes = quadro.shape[0] - (2 if fase == 1 else 1)
            
            linhas_possiveis = []
            for i_res in range(num_linhas_restricoes):
                elemento_aik = quadro[i_res, coluna_entrada]
                bi = quadro[i_res, -1]
                
                if elemento_aik > self.tol:
                    razoes.append(bi / elemento_aik)
                    linhas_possiveis.append(i_res)
                else:
                    razoes.append(float('inf'))
            
            # Se não existir razão válida (todas inf ou negativas), problema ilimitado
            if len(linhas_possiveis) == 0:
                print(f"\nProblema Ilimitado detectado na iteração {i}.")
                return quadro, "Ilimitado"
            
            razao_minima = min([razoes[idx] for idx in linhas_possiveis])
            
            # Identifica candidatos a sair
            candidatos_saida = [idx for idx in linhas_possiveis if abs(razoes[idx] - razao_minima) < self.tol]
            linha_saida = candidatos_saida[0]
            
            elemento_pivo = quadro[linha_saida, coluna_entrada]
            
            print(f"\nIteração {i} (Fase {fase}):")
            print(f"Entra: x_{coluna_entrada+1} | Sai: Linha {linha_saida+1} (Pivô: {elemento_pivo:.4f})")
            
            # 3. Pivoteamento
            # Normaliza a linha do pivô
            quadro[linha_saida, :] /= elemento_pivo
            
            # Zera a coluna do pivô nas outras linhas
            num_linhas_total = quadro.shape[0]
            for l in range(num_linhas_total):
                if l != linha_saida:
                    fator = quadro[l, coluna_entrada]
                    quadro[l, :] -= fator * quadro[linha_saida, :]
            
            self.imprimir_quadro(quadro, fase)
            i += 1

    def extrair_solucao(self, quadro):
        """Extrai as variáveis básicas e o valor da função objetivo do quadro final."""
        num_vars = self.n
        x_solucao = np.zeros(num_vars)
        num_linhas_restricoes = self.m
        
        # Identifica variáveis básicas procurando colunas identidade
        for j in range(num_vars):
            coluna = quadro[:num_linhas_restricoes, j]
            # Verifica se é uma coluna identidade
            soma_abs = np.sum(np.abs(coluna))
            max_val = np.max(coluna)
            
            if soma_abs <= 1.0 + self.tol and np.isclose(max_val, 1.0):
                # Encontrar a linha onde está o 1
                idx_linha = np.argmax(coluna)
                x_solucao[j] = quadro[idx_linha, -1]
        
        self.solucao = x_solucao
        self.valor_otimo = -quadro[-1, -1]
        
        print("\n" + "="*60)
        print("RESULTADO FINAL")
        print("="*60)
        print(f"\nTipo de Resultado: {self.status}")
        print(f"Valor Ótimo Z = {self.valor_otimo:.4f}")
        # Formatar vetor solução para string
        vetor_str = ", ".join([f"{val:.4f}" for val in self.solucao])
        print(f"Solução x*: [{vetor_str}]\n")

    def verificar_multiplas_solucoes(self, quadro):
        """Verifica se existem múltiplas soluções ótimas"""
        # Se uma variável nao básica tiver custo reduzido 0 no quadro ótimo
        custos_reduzidos = quadro[-1, :-1]
        
        possibilidade_multipla = False
        for j in range(self.n):
            # Se custo reduzido é zero
            if abs(custos_reduzidos[j]) < self.tol:
                # verifica se ela nao é básica
                coluna = quadro[:self.m, j]
                eh_canonica = (np.sum(np.abs(coluna)) <= 1.0 + self.tol and np.isclose(np.max(coluna), 1.0))
                
                if not eh_canonica:
                    possibilidade_multipla = True
                    break
        
        if possibilidade_multipla:
            print("Múltiplas soluções ótimas detectadas")

    def imprimir_quadro(self, quadro, fase):
        """Imprime o quadro (tableau) formatado no terminal"""
        linhas, colunas = quadro.shape
        print("-" * (10 * colunas))
        
        # Cabeçalho das colunas
        cabecalho = ["x"+str(i+1) for i in range(self.n)]
        if fase == 1:
            cabecalho += ["xa"+str(i+1) for i in range(self.m)]
        cabecalho += ["b"]
        
        # Caso dimensões não batam perfeitamente na string
        if len(cabecalho) != colunas:
             cabecalho = [f"C{i}" for i in range(colunas-1)] + ["b"]
            
        print(" | ".join([f"{h:>8}" for h in cabecalho]))
        print("-" * (10 * colunas))
        
        for i in range(linhas):
            tipo_linha = ""
            if fase == 1:
                if i == linhas - 2: tipo_linha = "(w)"
                elif i == linhas - 1: tipo_linha = "(z)"
                else: tipo_linha = f"(R{i+1})"
            else:
                if i == linhas - 1: tipo_linha = "(z)"
                else: tipo_linha = f"(R{i+1})"
                
            linha_str = " | ".join([f"{val:>8.3f}" for val in quadro[i, :]])
            print(f"{linha_str} {tipo_linha}")
        print("-" * (10 * colunas))

def obter_entrada():
    """Lê a entrada do usuário via manual ou arquivo."""
    print("Modo de Entrada:")
    print("1. Manual")
    print("2. Arquivo (formato txt: c na 1ª linha, A nas seguintes, b na última)")
    escolha = input("Escolha (1/2): ").strip()
    
    if escolha == '1':
        try:
            n_vars = int(input("Número de variáveis de decisão (n): "))
            n_restricoes = int(input("Número de restrições (m): "))
            
            print(f"Digite os coeficientes da função objetivo (c1 ... c{n_vars}) separados por espaço:")
            c = list(map(float, input().split()))
            
            A = []
            print(f"Digite as restrições (apenas coeficientes):")
            for i in range(n_restricoes):
                print(f"Restrição {i+1} (coeficientes a1...an):")
                linha = list(map(float, input().split()))
                A.append(linha)
                
            print("Digite os termos independentes (b) separados por espaço:")
            b = list(map(float, input().split()))
            
            return c, A, b
            
        except ValueError:
            print("Erro na entrada de dados.")
            sys.exit(1)
            
    elif escolha == '2':
        nome_arquivo = input("Nome do arquivo (ex: dados.txt): ").strip()
        try:
            with open(nome_arquivo, 'r') as f:
                linhas = [l.strip() for l in f.readlines() if l.strip()]
                c = list(map(float, linhas[0].split()))
                
                # Assume que a última linha é b, o meio é A
                b = list(map(float, linhas[-1].split()))
                
                A = []
                for linha in linhas[1:-1]:
                    A.append(list(map(float, linha.split())))
                
                return c, A, b
        except FileNotFoundError:
            print("Arquivo não encontrado.")
            sys.exit(1)
    else:
        print("Opção inválida.")
        sys.exit(1)

if __name__ == "__main__":
    print("TRABALHO 1 - SIMPLEX DUAS FASES")
    c, A, b = obter_entrada()
    
    if len(c) != len(A[0]) or len(b) != len(A):
        print("Erro: Dimensoes diferentes entre c, A e b.")
    else:
        solver = SimplexDuasFases(c, A, b)
        solver.resolver()