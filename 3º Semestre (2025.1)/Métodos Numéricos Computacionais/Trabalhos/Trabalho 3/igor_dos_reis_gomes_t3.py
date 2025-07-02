import os
import time
import numpy as np
import matplotlib.pyplot as plt
from tabulate import tabulate
import metodos as mt

# DADOS DO SISTEMA DO PROBLEMA
matriz_A = np.array([[10, 2, -1], [-3, -6, 2], [1, 1, 5]], dtype=float)
vetor_B = np.array([27, -61.5, -21.5], dtype=float)

# GERAÇÃO DO GRÁFICO DE CONVERGÊNCIA DOS MÉTODOS ITERATIVOS
def grafico_convergencia(hist_jacobi, it_jacobi, hist_seidel, it_seidel):
    plt.figure(figsize=(10, 6))
    
    for i in range(hist_jacobi.shape[1]):
        plt.plot(range(it_jacobi), hist_jacobi[:it_jacobi, i], linestyle='--', marker='o', label=f"Jacobi x{i+1}")
    
    for i in range(hist_seidel.shape[1]):
        plt.plot(range(it_seidel), hist_seidel[:it_seidel, i], linestyle='-', marker='s', label=f"Seidel x{i+1}")
    
    plt.xlabel("Iterações")
    plt.ylabel("Valores das Incógnitas")
    plt.title("Convergência dos Métodos Iterativos")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig("grafico_convergencia.png")
    plt.close()

# GERAÇÃO DO GRÁFICO DE QUANTIDADE DE ITERAÇÕES DOS MÉTODOS ITERATIVOS
def grafico_iteracoes(it_jacobi, it_seidel):
    plt.figure(figsize=(6, 6))
    plt.bar(["Jacobi", "Seidel"], [it_jacobi, it_seidel])
    plt.ylabel("Número de Iterações")
    plt.title("Comparação do Número de Iterações")
    plt.tight_layout()
    plt.savefig("grafico_iteracoes.png")
    plt.close()

# GERAÇÃO DA TABELA COM TODAS AS SOLUÇÕES DOS MÉTODOS
def gerar_tabela(solucoes, tempos, erros):
    nomes = ["LU", "Gauss-Compacto", "Cholesky", "Gauss-Jordan", "Jacobi", "Seidel"]
    
    def formatar(sol):
        if sol is None:
            return ["N/A"] * 3
        return [f"x{i+1} = {v:.6g}" for i, v in enumerate(sol)]
    
    dados = []
    for i, sol in enumerate(solucoes):
        linha = [nomes[i]] + formatar(sol) + [f"{tempos[i]:.2e}s"]
        linha.append(f"{erros[i]:.2e}" if erros[i] is not None else "N/A")
        dados.append(linha)
    
    fig = plt.figure(figsize=(12, 4))
    grid = plt.GridSpec(1, 1)
    ax = fig.add_subplot(grid[0])
    ax.axis("off")
    colunas = ["Método", "x₁", "x₂", "x₃", "Tempo", "Erro"]
    tabela = ax.table(cellText=dados, colLabels=colunas, loc="center", cellLoc="left")
    tabela.set_fontsize(10)
    tabela.scale(1.5, 2)
    plt.tight_layout()
    plt.savefig("tabela_solucoes.png")
    plt.close()

# EXECUÇÃO DO MÉTODO ESCOLHIDO NO MENU (MEDE TEMPO, PEGA SOLUÇÃO E ERRO)
def executar(metodo):
    tempos = [0] * 6
    erros = [None] * 6
    resultados = [None] * 6
    hist_j, hist_s = None, None
    it_j, it_s = 0, 0

    if metodo in [1, 7]:
        t0 = time.perf_counter()
        ok, L, U = mt.metodoDecomposicaoLU(matriz_A)
        resultados[0] = mt.solucao(L, U, vetor_B, ok)
        tempos[0] = time.perf_counter() - t0

    if metodo in [2, 7]:
        t0 = time.perf_counter()
        ok, L, U = mt.metodoGaussCompacto(matriz_A)
        resultados[1] = mt.solucao(L, U, vetor_B, ok)
        tempos[1] = time.perf_counter() - t0

    if metodo in [3, 7]:
        t0 = time.perf_counter()
        ok, L = mt.metodoCholesky(matriz_A)
        resultados[2] = mt.solucao(L, L.T, vetor_B, ok) if ok else None
        tempos[2] = time.perf_counter() - t0

    if metodo in [4, 7]:
        t0 = time.perf_counter()
        ok, res = mt.metodoGaussJordan(matriz_A, vetor_B)
        resultados[3] = res if ok else None
        tempos[3] = time.perf_counter() - t0

    if metodo in [5, 7]:
        t0 = time.perf_counter()
        ok, x, it_j, hist_j, erros[4] = mt.metodoJacobi(matriz_A, vetor_B)
        resultados[4] = x if ok else None
        tempos[4] = time.perf_counter() - t0

    if metodo in [6, 7]:
        t0 = time.perf_counter()
        ok, x, it_s, hist_s, erros[5] = mt.metodoGaussSeidel(matriz_A, vetor_B)
        resultados[5] = x if ok else None
        tempos[5] = time.perf_counter() - t0

    if metodo == 7:
        gerar_tabela(resultados, tempos, erros)
        grafico_convergencia(hist_j, it_j, hist_s, it_s)
        grafico_iteracoes(it_j, it_s)
        os.system('cls' if os.name == 'nt' else 'clear')
        print("Resultados salvos como imagens. Obrigado!")

    else:
        nomes = ["LU", "Gauss Compacto", "Cholesky", "Gauss-Jordan", "Jacobi", "Seidel"]
        idx = metodo - 1
        print(f"\nMétodo: {nomes[idx]}")
        if resultados[idx] is None:
            print("Solução: Não aplicável")
        else:
            dados = [[f"x{i+1}", f"{val:.6g}"] for i, val in enumerate(resultados[idx])]
            dados.append(["Tempo", f"{tempos[idx]:.2e}s"])
            erro = erros[idx] if idx >= 4 else "N/A"
            dados.append(["Erro", erro if erro == "N/A" else f"{erro:.2e}"])
            print(tabulate(dados, headers=["Variável", "Valor"], tablefmt="fancy_grid"))
        input("\nPressione Enter para voltar ao menu...")

    os.system('cls' if os.name == 'nt' else 'clear')

# MOSTRA O SISTEMA LINEAR EM TABELA DO PROBLEMA PROPOSTO
def mostrarSistema():
    cabecalho = ["Equação", "Sistema"]
    linhas = [
        ["1", "10x₁ +  2x₂ -  x₃ =  27"],
        ["2", "-3x₁ -  6x₂ + 2x₃ = -61.5"],
        ["3", " x₁ +   x₂ + 5x₃ = -21.5"]
    ]
    print(tabulate(linhas, headers=cabecalho, tablefmt="fancy_grid"))

# MAIN (MOSTRA MENU)
def main():
    os.system('cls' if os.name == 'nt' else 'clear')

    print("===== TRABALHO 3 - SISTEMAS DE EQUAÇÕES LINEARES =====")

    while True:
        mostrarSistema()

        print("\nEscolha o método a ser utilizado:")
        print("[1] Decomposição LU")
        print("[2] Gauss-Compacto")
        print("[3] Cholesky")
        print("[4] Gauss-Jordan")
        print("[5] Jacobi-Richardson")
        print("[6] Gauss-Seidel")
        print("[7] Comparar todos")
        print("[8] Sair")
        try:
            opcao = int(input("--> "))
            if opcao == 8:
                print("Encerrando...")
                break
            elif 1 <= opcao <= 7:
                executar(opcao)
            else:
                print("Opção inválida.")
        except ValueError:
            print("Digite um número válido.")

if __name__ == "__main__":
    main()