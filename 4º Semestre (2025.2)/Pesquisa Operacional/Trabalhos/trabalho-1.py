"""
Trabalho 2 - Método Branch & Bound - Pesquisa Operacional
Aluno: Igor dos Reis Gomes
RA: 241025265
"""

import numpy as np
import sys
import math

# Configurações do Numpy
np.set_printoptions(precision=4, suppress=True, linewidth=150)

class SimplexDuasFases:
    """
    Implementação do Método Simplex de Duas Fases.
    Totalmente silenciosa (sem prints), retorna apenas status e valores.
    """
    
    def __init__(self, c, A, b):
        self.c = np.array(c, dtype=float)
        self.A = np.array(A, dtype=float)
        self.b = np.array(b, dtype=float)
        self.m, self.n = self.A.shape
        self.status = "Não Iniciado"
        self.solucao = None
        self.valor_otimo = float('inf') 
        self.tol = 1e-9

    def resolver(self):
        # --- FASE I ---
        num_linhas_total = self.m + 2
        num_colunas_total = self.n + self.m + 1
        quadro = np.zeros((num_linhas_total, num_colunas_total))
        
        identidade_artificiais = np.eye(self.m)
        quadro[:self.m, :self.n] = self.A
        quadro[:self.m, self.n:self.n+self.m] = identidade_artificiais
        quadro[:self.m, -1] = self.b
        quadro[self.m+1, :self.n] = self.c
        
        # Monta função W
        for j in range(num_colunas_total):
            if j < self.n:
                quadro[self.m, j] = -np.sum(quadro[:self.m, j])
            elif j >= self.n and j < self.n + self.m:
                quadro[self.m, j] = 0
            else:
                quadro[self.m, j] = -np.sum(quadro[:self.m, j])

        quadro, status_w = self.executar_iteracoes(quadro, self.m, 1)

        if status_w == "Ilimitado":
            return "Ilimitado", None, None

        valor_w = -quadro[self.m, -1]
        
        # Se w > 0, é inviável
        if abs(valor_w) > 1e-5:
            return "Inviável", None, None
        
        # --- FASE II ---
        quadro_fase2 = np.delete(quadro, slice(self.n, self.n + self.m), axis=1)
        quadro_fase2 = np.delete(quadro_fase2, self.m, axis=0)
        
        quadro_final, status_z = self.executar_iteracoes(quadro_fase2, self.m, 2)
        
        self.status = status_z
        
        if self.status == "Ótimo":
            x_sol = self.extrair_solucao(quadro_final)
            z_opt = -quadro_final[-1, -1]
            return "Ótimo", z_opt, x_sol
        else:
            return self.status, None, None

    def executar_iteracoes(self, quadro, linha_alvo, fase):
        iteracao = 1
        while True:
            custos = quadro[linha_alvo, :-1]
            min_custo = np.min(custos)
            
            if min_custo >= -self.tol:
                return quadro, "Ótimo"
            
            col_entrada = np.where(custos == min_custo)[0][0]
            
            # Teste da Razão
            razoes = []
            linhas_idx = []
            num_restricoes = quadro.shape[0] - (2 if fase == 1 else 1)
            
            for i in range(num_restricoes):
                val = quadro[i, col_entrada]
                b_val = quadro[i, -1]
                if val > self.tol:
                    razoes.append(b_val / val)
                    linhas_idx.append(i)
            
            if not razoes:
                return quadro, "Ilimitado"
            
            min_razao = min(razoes)
            idx_local = razoes.index(min_razao)
            linha_saida = linhas_idx[idx_local]
            
            pivo = quadro[linha_saida, col_entrada]
            quadro[linha_saida, :] /= pivo
            
            for l in range(quadro.shape[0]):
                if l != linha_saida:
                    fator = quadro[l, col_entrada]
                    quadro[l, :] -= fator * quadro[linha_saida, :]
            
            iteracao += 1
            if iteracao > 2000: # Limite para nao ter loop infinito
                return quadro, "Inviável"

    def extrair_solucao(self, quadro):
        x = np.zeros(self.n)
        for j in range(self.n):
            col = quadro[:self.m, j]
            if np.sum(np.abs(col)) <= 1.0 + 1e-5 and np.isclose(np.max(col), 1.0):
                idx = np.argmax(col)
                x[j] = quadro[idx, -1]
        return x

class NoBranchBound:
    def __init__(self, A, b, restricoes_adicionais=None, nivel=0):
        self.A = A
        self.b = b
        self.historico = restricoes_adicionais if restricoes_adicionais else []
        self.nivel = nivel
        self.z = float('inf')
        self.x = None

class BranchAndBound:
    """
    Controlador do Método Branch & Bound
    """
    def __init__(self, c, A, b, vars_inteiras, estrategia='depth'):
        self.c = c
        self.A_original = np.array(A)
        self.b_original = np.array(b)
        self.vars_inteiras = vars_inteiras
        self.estrategia = estrategia
        
        self.melhor_solucao = None
        self.melhor_z = float('inf')
        self.nos_explorados = 0

    def resolver(self):
        print(f"\n{'=' * 60}")
        print(f"INICIANDO BRANCH & BOUND (Estratégia: {self.estrategia})")
        print(f"{'=' * 60}")
        
        raiz = NoBranchBound(self.A_original, self.b_original)
        fila_nos = [raiz]
        
        while fila_nos:
            # 1. Seleção de Nó
            no_atual = self.selecionar_no(fila_nos)
            self.nos_explorados += 1
            
            print(f"\n>> Processando Nó {self.nos_explorados} (Nível {no_atual.nivel})")
            if no_atual.historico:
                print(f"   Restrições adicionadas: {no_atual.historico[-1]}")

            # 2. Resolver Relaxação Linear
            A_padrao, c_padrao, b_padrao = self.preparar_simplex(no_atual.A, self.c, no_atual.b)
            
            solver = SimplexDuasFases(c_padrao, A_padrao, b_padrao)
            status, z, x = solver.resolver()
            
            if x is not None:
                x = x[:len(self.c)]
            
            print(f"   Status Simplex: {status}")
            if z is not None:
                print(f"   Z (Relaxado): {z:.4f}")
                print(f"   X: {np.round(x, 4)}")

            # 3. Análise do Resultado (Poda)
            # Caso 1: Inviável
            if status == "Inviável" or status == "Ilimitado":
                print("   -> PODA: Inviabilidade.")
                continue
                
            # Caso 2: Poda por Limitante (Bound)
            if z >= self.melhor_z - 1e-7:
                print(f"   -> PODA: Limitante ({z:.4f} >= Melhor Z {self.melhor_z:.4f}).")
                continue
                
            # Caso 3: Solução Inteira
            viavel_inteira = True
            var_fracionaria_idx = -1
            
            for idx in self.vars_inteiras:
                val = x[idx]
                if not (abs(val - round(val)) < 1e-5):
                    viavel_inteira = False
                    var_fracionaria_idx = idx
                    break
            
            if viavel_inteira:
                print(f"   -> SOLUÇÃO INTEIRA ENCONTRADA! Z = {z:.4f}")
                if z < self.melhor_z:
                    self.melhor_z = z
                    self.melhor_solucao = x
                    print("   -> Nova melhor solução global atualizada.")
                else:
                    print("   -> Pior que a atual melhor, descarta")
            else:
                # Caso 4: Ramificação
                print(f"   -> RAMIFICAÇÃO: Variável x_{var_fracionaria_idx + 1} fracionária ({x[var_fracionaria_idx]:.4f})")
                self.ramificar(no_atual, var_fracionaria_idx, x[var_fracionaria_idx], fila_nos)

        self.apresentar_resultado_final()

    def preparar_simplex(self, A_in, c_in, b_in):
        A_calc = A_in.copy()
        b_calc = b_in.copy()
        m, n = A_calc.shape
        slacks = np.zeros((m, m))
        
        for i in range(m):
            if b_calc[i] < 0:
                b_calc[i] = -b_calc[i]
                A_calc[i, :] = -A_calc[i, :]
                slacks[i, i] = -1.0 
            else:
                slacks[i, i] = 1.0

        A_out = np.hstack((A_calc, slacks))
        c_out = np.concatenate((c_in, np.zeros(m)))
        return A_out, c_out, b_calc

    def selecionar_no(self, fila):
        if self.estrategia == 'depth':
            return fila.pop() 
        elif self.estrategia == 'breadth':
            return fila.pop(0)
        else:
            return fila.pop()

    def ramificar(self, no_pai, idx_var, valor_frac, fila):
        floor_val = math.floor(valor_frac)
        ceil_val = math.ceil(valor_frac)
        
        # Filho 1: x_i <= floor_val
        nova_linha = np.zeros(no_pai.A.shape[1])
        nova_linha[idx_var] = 1.0
        
        A_novo1 = np.vstack((no_pai.A, nova_linha))
        b_novo1 = np.append(no_pai.b, floor_val)
        
        hist1 = no_pai.historico + [(f"x{idx_var+1}", "<=", floor_val)]
        filho1 = NoBranchBound(A_novo1, b_novo1, hist1, no_pai.nivel + 1)
        
        # Filho 2: x_i >= ceil_val
        nova_linha_2 = np.zeros(no_pai.A.shape[1])
        nova_linha_2[idx_var] = -1.0 
        
        A_novo2 = np.vstack((no_pai.A, nova_linha_2))
        b_novo2 = np.append(no_pai.b, -ceil_val) 
        
        hist2 = no_pai.historico + [(f"x{idx_var + 1}", ">=", ceil_val)]
        filho2 = NoBranchBound(A_novo2, b_novo2, hist2, no_pai.nivel + 1)
        
        fila.append(filho1)
        fila.append(filho2)

    def apresentar_resultado_final(self):
        print("\n" + "="*60)
        print("RESULTADO FINAL DO BRANCH & BOUND")
        print("="*60)
        if self.melhor_solucao is not None:
            print(f"Solução Ótima Inteira Encontrada:")
            print(f"Z = {self.melhor_z:.4f}")
            sol_str = ", ".join([f"{v:.4f}" for v in self.melhor_solucao])
            print(f"Variáveis (x): [{sol_str}]")
            print(f"Total de nós explorados: {self.nos_explorados}")
        else:
            print("Nenhuma solução inteira viável encontrada.")

def obter_entrada():
    print("\n--- Entrada de Dados ---")
    print("1. Entrada Manual")
    print("2. Ler Arquivo")
    opcao = input("Escolha: ").strip()
    
    c, A, b, var_int = [], [], [], []
    
    if opcao == '1':
        try:
            n = int(input("Número de variáveis: "))
            m = int(input("Número de restrições: "))
            
            print("Coeficientes da Função Objetivo: ")
            c = list(map(float, input().split()))
            
            print("Restrições: ")
            A = []
            for i in range(m):
                row = list(map(float, input(f"Restrição {i+1}: ").split()))
                A.append(row)
                
            print("Vetor b:")
            b = list(map(float, input().split()))
            
            print(f"Indice das variaveis que são inteiras [inicia em 1] (ou 'todas'): ")
            resp = input().strip().lower()
            if resp == 'todas':
                var_int = list(range(n))
            else:
                var_int = [int(x) - 1 for x in resp.split()]
                
        except ValueError:
            print("Erro na entrada.")
            sys.exit(1)
            
    elif opcao == '2':
        nome = input("Nome do arquivo (txt): ")
        try:
            with open(nome, 'r') as f:
                lines = [l.strip() for l in f.readlines() if l.strip() and not l.startswith('#')]
                c = list(map(float, lines[0].split()))
                b_raw = lines[-1].split()
                b = list(map(float, b_raw))
                A = []
                for l in lines[1:-1]:
                    A.append(list(map(float, l.split())))
            
                print(f"Arquivo lido. Identificadas {len(c)} variáveis.")
                print(f"Quais são inteiras? (indices 1..n ou 'todas'):")
                resp = input().strip().lower()
                if resp == 'todas':
                    var_int = list(range(len(c)))
                else:
                    var_int = [int(x) - 1 for x in resp.split()]
                    
        except FileNotFoundError:
            print("Arquivo não encontrado.")
            sys.exit(1)
            
    return c, A, b, var_int

if __name__ == "__main__":
    print("MÉTODO BRANCH & BOUND - OTIMIZAÇÃO INTEIRA")
    
    c, A, b, vars_int = obter_entrada()
    
    print("\nEstratégia de Busca:")
    print("1. Profundidade (Depth-First) - Padrão")
    print("2. Largura (Breadth-First)")
    escolha_map = {'1': 'depth', '2': 'breadth'}
    escolha = input("Digite (1/2): ").strip()
    escolha = escolha_map.get(escolha, 'depth')
    
    resolver_branchbound = BranchAndBound(c, A, b, vars_int, estrategia = escolha)
    resolver_branchbound.resolver()