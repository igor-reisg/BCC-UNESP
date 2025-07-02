import os
import time
import math
import numpy as np
import matplotlib.pyplot as plt
from tabulate import tabulate

# EQUAÇÕES
def g1(x): return x**2 + 2*x + 1
def g2(x): return math.sin(x)
def g3(x): return math.exp(x)

# EQUAÇÕES VETORIZADAS
def g1_vec(x): return x**2 + 2*x + 1
def g2_vec(x): return np.sin(x)
def g3_vec(x): return np.exp(x)

# VALORES EXATOS INTEGRAIS
integraisExatas = {
    "g1": 53.333333333333336,
    "g2": 2.0,
    "g3": math.exp(2) - 1
}

# MÉTODO DO TRAPÉZIO
def metodoTrapezio(func, inicio, fim, n):
    h = (fim - inicio) / n
    soma = func(inicio) + func(fim)
    for i in range(1, n):
        soma += 2 * func(inicio + i * h)
    return h * soma / 2, None

# MÉTODO DE 1/3 DE SIMPSON
def metodo13Simpson(func, inicio, fim, n):
    if n % 2 != 0:
        return None, "Simpson 1/3 requer número par de subintervalos."
    h = (fim - inicio) / n
    soma = func(inicio) + func(fim)
    for i in range(1, n):
        peso = 4 if i % 2 != 0 else 2
        soma += peso * func(inicio + i * h)
    return h * soma / 3, None

# MÉTODO DE 3/8 DE SIMPSON
def metodo38Simpson(func, inicio, fim, n):
    if n % 3 != 0:
        return None, "Simpson 3/8 requer número de subintervalos múltiplo de 3."
    h = (fim - inicio) / n
    soma = func(inicio) + func(fim)
    for i in range(1, n):
        if i % 3 == 0:
            peso = 2
        else:
            peso = 3
        soma += peso * func(inicio + i * h)
    return 3 * h * soma / 8, None

# ERROS
def erroAbs(aprox, real): return abs(real - aprox)
def erroRel(aprox, real): return erroAbs(aprox, real) / abs(real)

# Gráficos
def plotGraficos(func_vec, a, b, real, dados, nome_dir):
    os.makedirs(nome_dir, exist_ok=True)
    x = np.linspace(a, b, 1000)
    y = func_vec(x)

    # COMPARAÇÃO APROXIMAÇÕES
    plt.figure()
    plt.plot(x, y, label="f(x)", color="black")
    for metodo, info in dados.items():
        if 'aprox' in info:
            plt.axhline(y=info['aprox'], linestyle="--", label=f"{metodo} (≈ {info['aprox']:.4f})")
    plt.axhline(y=real, color="green", linestyle="-", label=f"Valor real (≈ {real:.4f})")
    plt.title("Comparação das Aproximações")
    plt.legend()
    plt.savefig(f"{nome_dir}/aproximacoes.png")
    plt.close()

    # ERRO ABSOLUTO
    plt.figure()
    metodos = [m for m in dados.keys() if "erro_abs" in dados[m]]
    erros_abs = [dados[m]["erro_abs"] for m in metodos]
    plt.bar(metodos, erros_abs, color="tomato")
    plt.title("Erro Absoluto")
    plt.savefig(f"{nome_dir}/erro_abs.png")
    plt.close()

    # ERRO RELATIVO
    plt.figure()
    metodos_rel = [m for m in dados.keys() if "erro_rel" in dados[m]]
    erros_rel = [dados[m]["erro_rel"] for m in metodos_rel]
    plt.bar(metodos_rel, erros_rel, color="skyblue")
    plt.title("Erro Relativo")
    plt.savefig(f"{nome_dir}/erro_rel.png")
    plt.close()

# Execução dos métodos
def resolveIntegral(func, func_vec, a, b, exato, nome_func, pasta_saida):
    metodos = {
        "Trapézio": (metodoTrapezio, 10),
        "Simpson 1/3": (metodo13Simpson, 10),
        "Simpson 3/8": (metodo38Simpson, 6)
    }

    resultados = {}

    # EXECUÇÃO DOS MÉTODOS
    for nome_metodo, (metodo, n) in metodos.items():
        inicio = time.perf_counter()
        resultado, erro_msg = metodo(func, a, b, n)
        tempo = time.perf_counter() - inicio

        if erro_msg:
            resultados[nome_metodo] = {"erro": erro_msg}
        else:
            resultados[nome_metodo] = {
                "aprox": resultado,
                "erro_abs": erroAbs(resultado, exato),
                "erro_rel": erroRel(resultado, exato),
                "tempo": tempo,
                "subdivs": n
            }

    plotGraficos(func_vec, a, b, exato, resultados, pasta_saida)

    # TABELA DE RESULTADOS
    tabela = []
    for metodo, res in resultados.items():
        if "erro" in res:
            tabela.append([metodo, "Erro", res["erro"], "-", "-", "-"])
        else:
            tabela.append([
                metodo,
                f"{res['aprox']:.8f}",
                f"{res['erro_abs']:.2e}",
                f"{res['erro_rel']:.2%}",
                res['subdivs'],
                f"{res['tempo']:.2e} s"
            ])

    headers = ["Método", "Aproximação", "Erro Absoluto", "Erro Relativo", "Subintervalos", "Tempo Execução"]
    print(f"\nResultados para {nome_func}:")
    print(tabulate(tabela, headers=headers, tablefmt="fancy_grid"))

# MENU
def menu():
    os.system("cls" if os.name == "nt" else "clear")
    while True:
        print("\n===== TRABALHO 6 - INTEGRAÇÃO NUMÉRICA =====\n")
        print("1. f(x) = x² + 2x + 1     [0, 4]")
        print("2. f(x) = sin(x)          [0, π]")
        print("3. f(x) = e^x             [0, 2]")
        print("4. Sair")
        escolha = input("--> ")

        if escolha == '1':
            os.system("cls" if os.name == "nt" else "clear")
            resolveIntegral(g1, g1_vec, 0, 4, integraisExatas["g1"], "f(x) = x² + 2x + 1", "saida_funcao1")
        elif escolha == '2':
            os.system("cls" if os.name == "nt" else "clear")
            resolveIntegral(g2, g2_vec, 0, math.pi, integraisExatas["g2"], "f(x) = sin(x)", "saida_funcao2")
        elif escolha == '3':
            os.system("cls" if os.name == "nt" else "clear")
            resolveIntegral(g3, g3_vec, 0, 2, integraisExatas["g3"], "f(x) = e^x", "saida_funcao3")
        elif escolha == '4':
            print("Encerrando o programa.")
            break
        else:
            print("Opção inválida. Tente novamente.")

if __name__ == "__main__":
    menu()
