import math
import time
import matplotlib.pyplot as plt
import funcoes

# Função para plotar o gráfico comparativo entre os Métodos para cada Problema resolvido
def plot_comparativo(itB, itF, itN, tempoB, tempoF, tempoN):
    metodos = ['Bisseção', 'Falsa Posição', 'Newton-Raphson']
    iteracoes = [itB, itF, itN]
    tempos = [tempoB, tempoF, tempoN]

    # Gráfico 1
    plt.figure(figsize=(10, 6))
    plt.bar(metodos, iteracoes, color=['dodgerblue', 'darkorange', 'forestgreen'])
    plt.title("Número de Iterações por Método")
    plt.ylabel("Iterações")
    plt.tight_layout()
    plt.show()

    # Gráfico 2
    plt.figure(figsize=(10, 6))
    plt.plot(metodos, tempos, marker='s', linestyle='dashed', color='darkgreen', label='Tempo')
    plt.title("Tempo de Execução por Método")
    plt.ylabel("Tempo (s)")
    plt.grid(True)
    plt.tight_layout()
    plt.show()

def plot_convergencia(valores_bissecao, valores_falsaposicao, valores_newton):
    plt.figure(figsize=(12, 7))
    
    cores = ['blue', 'orange', 'green']
    
    if valores_bissecao:
        plt.plot(range(len(valores_bissecao)), valores_bissecao, 'o-', color=cores[0], label='Bisseção')
    
    if valores_falsaposicao:
        plt.plot(range(len(valores_falsaposicao)), valores_falsaposicao, 's-', color=cores[1], label='Falsa Posição')
    
    if valores_newton:
        plt.plot(range(len(valores_newton)), valores_newton, '^-', color=cores[2], label='Newton-Raphson')
    
    plt.title('Convergência dos Métodos Iterativos')
    plt.xlabel('Iterações')
    plt.ylabel('Valor da Raiz')
    plt.grid(True)
    plt.legend()
    plt.show()

# Resolução do Problema 1
def ex01():
    print("\nProblema 1 - Economia")
    usar_padrao = input("Usar valores padrão? (s/n): ").strip().lower()

    if usar_padrao == 'n':
        a = float(input("Informe o valor de a: "))
        b = float(input("Informe o valor de b: "))
        x0 = float(input("Informe o valor de x0: "))
        erro = float(input("Informe o valor do erro: "))
    else:
        a, b = 0, 30
        x0 = 1
        erro = 1e-5
        print(f"\nUsando valores padrão: a = {a}, b = {b}, x0 = {x0}, erro = {erro}\n")

    raizBissecao, itB, tempoB, valores_bissecao = funcoes.metBissecao(funcoes.funcaoEx1, a, b, erro)
    raizFalsaPosicao, itF, tempoF, valores_falsaposicao = funcoes.metFalsaPosicao(funcoes.funcaoEx1, a, b, erro)
    raizNewton, itN, tempoN, valores_newton = funcoes.metNewton(funcoes.funcaoEx1, funcoes.dfEx1, x0, erro)
    
    if raizBissecao is not None:
        print(f"\nValor de p (Bisseção): {raizBissecao:.5f}")
    
    if raizFalsaPosicao is not None:
        print(f"Valor de p (Falsa Posição): {raizFalsaPosicao:.5f}")

    if raizNewton is not None:
        print(f"Valor de p (Newton-Raphson): {raizNewton:.5f}\n")

    print(f"Iterações (Bisseção): {itB}, Tempo: {tempoB:.8f} s")
    print(f"Iterações (Falsa Posição): {itF}, Tempo: {tempoF:.8f} s")
    print(f"Iterações (Newton-Raphson): {itN}, Tempo: {tempoN:.8f} s\n")

    plot_convergencia(valores_bissecao, valores_falsaposicao, valores_newton)
    
    plot_comparativo(itB, itF, itN, tempoB, tempoF, tempoN)

# Resolução do Problema 2
def ex02():
    print("\nProblema 2 - Engenharia")
    usar_padrao = input("Usar valores padrão? (s/n): ").strip().lower()

    if usar_padrao == 'n':
        a = float(input("Informe o valor de a: "))
        b = float(input("Informe o valor de b: "))
        x0 = float(input("Informe o valor de x0: "))
        erro = float(input("Informe o valor do erro: "))
    else:
        a, b = 0.5, 0.6
        x0 = 1
        erro = 1e-5
        print(f"\nUsando valores padrão: a = {a}, b = {b}, x0 = {x0}, erro = {erro}\n")

    raizBissecao, itB, tempoB, valores_bissecao = funcoes.metBissecao(funcoes.funcaoEx2, a, b, erro)
    raizFalsaPosicao, itF, tempoF, valores_falsaposicao = funcoes.metFalsaPosicao(funcoes.funcaoEx2, a, b, erro)
    raizNewton, itN, tempoN, valores_newton = funcoes.metNewton(funcoes.funcaoEx2, funcoes.dfEx2, x0, erro)

    if raizBissecao is not None:
        print(f"\nValor de V (Bisseção): {raizBissecao:.5f}")

    if raizFalsaPosicao is not None:
        print(f"Valor de V (Falsa Posição): {raizFalsaPosicao:.5f}")

    if raizNewton is not None:
        print(f"Valor de V (Newton-Raphson): {raizNewton:.5f}\n")

    print(f"Iterações (Bisseção): {itB}, Tempo: {tempoB:.8f} s")
    print(f"Iterações (Falsa Posição): {itF}, Tempo: {tempoF:.8f} s")
    print(f"Iterações (Newton-Raphson): {itN}, Tempo: {tempoN:.8f} s\n")

    plot_convergencia(valores_bissecao, valores_falsaposicao, valores_newton)
    
    plot_comparativo(itB, itF, itN, tempoB, tempoF, tempoN)

# Resolução do Problema 3
def ex03():
    print("\nProblema 3 - Química")
    usar_padrao = input("Usar valores padrão? (s/n): ").strip().lower()

    if usar_padrao == 'n':
        a = float(input("Informe o valor de a: "))
        b = float(input("Informe o valor de b: "))
        x0 = float(input("Informe o valor de x0: "))
        erro = float(input("Informe o valor do erro: "))
    else:
        a, b = 0, 0.035
        x0 = 0.01
        erro = 1e-5
        print(f"\nUsando valores padrão: a = {a}, b = {b}, x0 = {x0}, erro = {erro}\n")

    raizBissecao, itB, tempoB, valores_bissecao = funcoes.metBissecao(funcoes.funcaoEx3, a, b, erro)
    raizFalsaPosicao, itF, tempoF, valores_falsaposicao = funcoes.metFalsaPosicao(funcoes.funcaoEx3, a, b, erro)
    raizNewton, itN, tempoN, valores_newton = funcoes.metNewton(funcoes.funcaoEx3, funcoes.dfEx3, x0, erro)

    if raizBissecao is not None:
        print(f"\nValor de x (Bisseção): {raizBissecao:.5f}")

    if raizFalsaPosicao is not None:
        print(f"Valor de x (Falsa Posição): {raizFalsaPosicao:.5f}")

    if raizNewton is not None:
        print(f"Valor de x (Newton-Raphson): {raizNewton:.5f}\n")

    print(f"Iterações (Bisseção): {itB}, Tempo: {tempoB:.8f} s")
    print(f"Iterações (Falsa Posição): {itF}, Tempo: {tempoF:.8f} s")
    print(f"Iterações (Newton-Raphson): {itN}, Tempo: {tempoN:.8f} s\n")

    plot_convergencia(valores_bissecao, valores_falsaposicao, valores_newton)
    
    plot_comparativo(itB, itF, itN, tempoB, tempoF, tempoN)

# Resolução do Problema 4
def ex04():
    print("\nProblema 4 - Física")
    usar_padrao = input("Usar valores padrão? (s/n): ").strip().lower()

    if usar_padrao == 'n':
        epsilon = float(input("Informe o valor de epsilon: "))
        sigma = float(input("Informe o valor de sigma: "))
        a = float(input("Informe o valor de a (limite inferior de r): "))
        b = float(input("Informe o valor de b (limite superior de r): "))
        x0 = float(input("Informe o valor de x0 (valor inicial para o método de Newton): "))
        erro = float(input("Informe o valor do erro: "))
    else:
        epsilon = 1.0
        sigma = 1.0
        a, b = 1, 1.5
        x0 = 1
        erro = 1e-5
        print(f"\nUsando valores padrão: epsilon = {epsilon}, sigma = {sigma}, a = {a}, b = {b}, x0 = {x0}, erro = {erro}\n")

    def f(r):
        return funcoes.funcaoEx4(epsilon, sigma, r)

    def df(r):
        return funcoes.dfEx4(epsilon, sigma, r)

    raizBissecao, itB, tempoB, valores_bissecao = funcoes.metBissecao(f, a, b, erro)
    raizFalsaPosicao, itF, tempoF, valores_falsaposicao = funcoes.metFalsaPosicao(f, a, b, erro)
    raizNewton, itN, tempoN, valores_newton = funcoes.metNewton(f, df, x0, erro)

    if raizBissecao is not None:
        print(f"\nValor de r (Bisseção): {raizBissecao:.5f}")

    if raizFalsaPosicao is not None:
        print(f"Valor de r (Falsa Posição): {raizFalsaPosicao:.5f}")

    if raizNewton is not None:
        print(f"Valor de r (Newton-Raphson): {raizNewton:.5f}\n")

    print(f"Iterações (Bisseção): {itB}, Tempo: {tempoB:.8f} s")
    print(f"Iterações (Falsa Posição): {itF}, Tempo: {tempoF:.8f} s")
    print(f"Iterações (Newton-Raphson): {itN}, Tempo: {tempoN:.8f} s\n")

    plot_convergencia(valores_bissecao, valores_falsaposicao, valores_newton)
    
    plot_comparativo(itB, itF, itN, tempoB, tempoF, tempoN)

# Resolução do Problema 5
def ex05():
    print("\nProblema 5 - Engenharia")
    usar_padrao = input("Usar valores padrão? (s/n): ").strip().lower()

    if usar_padrao == 'n':
        a = float(input("Informe o valor de a: "))
        b = float(input("Informe o valor de b: "))
        x0 = float(input("Informe o valor de x0: "))
        erro = float(input("Informe o valor do erro: "))
    else:
        a, b = 0.1, 2.0
        x0 = 1.0
        erro = 1e-5
        print(f"\nUsando valores padrão: a = {a}, b = {b}, x0 = {x0}, erro = {erro}\n")

    raizBissecao, itB, tempoB, valores_bissecao = funcoes.metBissecao(funcoes.funcaoEx5, a, b, erro)
    raizFalsaPosicao, itF, tempoF, valores_falsaposicao = funcoes.metFalsaPosicao(funcoes.funcaoEx5, a, b, erro)
    raizNewton, itN, tempoN, valores_newton = funcoes.metNewton(funcoes.funcaoEx5, funcoes.dfEx5, x0, erro)

    if raizBissecao is not None:
        print(f"\nValor de K (Bisseção): {raizBissecao:.5f}")

    if raizFalsaPosicao is not None:
        print(f"Valor de K (Falsa Posição): {raizFalsaPosicao:.5f}")
        
    if raizNewton is not None:
        print(f"Valor de K (Newton-Raphson): {raizNewton:.5f}\n")

    print(f"Iterações (Bisseção): {itB}, Tempo: {tempoB:.8f} s")
    print(f"Iterações (Falsa Posição): {itF}, Tempo: {tempoF:.8f} s")
    print(f"Iterações (Newton-Raphson): {itN}, Tempo: {tempoN:.8f} s\n")

    plot_convergencia(valores_bissecao, valores_falsaposicao, valores_newton)
    
    plot_comparativo(itB, itF, itN, tempoB, tempoF, tempoN)

def main():

    continuar = 's'
    while continuar == 's':
        print("\nTRABALHO 1 - MÉTODOS NUMÉRICOS")
        print("\nEscolha o problema:")
        print("[Problema 1] Economia")
        print("[Problema 2] Engenharia (Diodo)")
        print("[Problema 3] Química")
        print("[Problema 4] Física")
        print("[Problema 5] Controle\n")
        opcao = input("Digite o número do problema: ")

        if opcao == "1":
            ex01()
        elif opcao == "2":
            ex02()
        elif opcao == "3":
            ex03()
        elif opcao == "4":
            ex04()
        elif opcao == "5":
            ex05()
        else:
            print("Opção inválida.")

        continuar = input("Deseja continuar? (s/n) ").strip().lower()
        if continuar == 'n':
            print("\nFinalizando o programa...\n")

if __name__ == '__main__':
    main()