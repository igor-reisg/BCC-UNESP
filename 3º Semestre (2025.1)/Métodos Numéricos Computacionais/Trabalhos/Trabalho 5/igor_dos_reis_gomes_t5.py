import os
import numpy as np
import matplotlib.pyplot as plt
from math import log, e, sqrt
from tabulate import tabulate

# FUNÇÕES AUXILIARES PARA RESOLUÇÃO DOS MÉTODOS
def acumulo(v): return sum(v)
def acumuloPotencia(v, g): return sum(x**g for x in v)
def produtoSimples(a, b): return sum(x * y for x, y in zip(a, b))
def produtoPotencia(a, b, p): return sum((x**p) * y for x, y in zip(a, b))
def logaritmo_natural(v): l = [log(x) for x in v]; return sum(l), l

def erro_total(y): return sum((yi - np.mean(y))**2 for yi in y)
def erro_residual(y, y_calc): return sum((yi - yj)**2 for yi, yj in zip(y, y_calc))
def erro_medio(sqr, n): return sqrt(sqr / n)
def r2(sqt, sqr): return 1 - sqr / sqt

# IMPLEMENTAÇÃO DO MÉTODO DE AJUSTE LINEAR
def ajuste_linear(x, y):
    A = np.array([[len(x), acumulo(x)], [acumulo(x), acumuloPotencia(x, 2)]])
    
    b = np.array([acumulo(y), produtoSimples(x, y)])
    
    coef = np.linalg.solve(A, b)
    
    return coef[1], coef[0]

# IMPLEMENTAÇÃO DO MÉTODO DE AJUSTE POLINOMIAL GRAU 2
def ajuste_poli2(x, y):
    A = np.array([
        [len(x), acumulo(x), acumuloPotencia(x, 2)],
        [acumulo(x), acumuloPotencia(x, 2), acumuloPotencia(x, 3)],
        [acumuloPotencia(x, 2), acumuloPotencia(x, 3), acumuloPotencia(x, 4)]
    ])

    b = np.array([acumulo(y), produtoSimples(x, y), produtoPotencia(x, y, 2)])
    
    coef = np.linalg.solve(A, b)
    
    return coef[::-1]

# IMPLEMENTAÇÃO DO MÉTODO DE AJUSTE POLINOMIAL GRAU 3
def ajuste_poli3(x, y):
    A = np.array([
        [len(x), acumulo(x), acumuloPotencia(x, 2), acumuloPotencia(x, 3)],
        [acumulo(x), acumuloPotencia(x, 2), acumuloPotencia(x, 3), acumuloPotencia(x, 4)],
        [acumuloPotencia(x, 2), acumuloPotencia(x, 3), acumuloPotencia(x, 4), acumuloPotencia(x, 5)],
        [acumuloPotencia(x, 3), acumuloPotencia(x, 4), acumuloPotencia(x, 5), acumuloPotencia(x, 6)]
    ])

    b = np.array([acumulo(y), produtoSimples(x, y), produtoPotencia(x, y, 2), produtoPotencia(x, y, 3)])
    
    coef = np.linalg.solve(A, b)
    
    return coef[::-1]

# IMPLEMENTAÇÃO DO MÉTODO DE AJUSTE POLINOMIAL GRAU 4
def ajuste_poli4(x, y):
    A = np.array([
        [len(x), acumulo(x), acumuloPotencia(x, 2), acumuloPotencia(x, 3), acumuloPotencia(x, 4)],
        [acumulo(x), acumuloPotencia(x, 2), acumuloPotencia(x, 3), acumuloPotencia(x, 4), acumuloPotencia(x, 5)],
        [acumuloPotencia(x, 2), acumuloPotencia(x, 3), acumuloPotencia(x, 4), acumuloPotencia(x, 5), acumuloPotencia(x, 6)],
        [acumuloPotencia(x, 3), acumuloPotencia(x, 4), acumuloPotencia(x, 5), acumuloPotencia(x, 6), acumuloPotencia(x, 7)],
        [acumuloPotencia(x, 4), acumuloPotencia(x, 5), acumuloPotencia(x, 6), acumuloPotencia(x, 7), acumuloPotencia(x, 8)]
    ])
    b = np.array([
        acumulo(y), produtoSimples(x, y), produtoPotencia(x, y, 2), produtoPotencia(x, y, 3), produtoPotencia(x, y, 4)
    ])
    coef = np.linalg.solve(A, b)
    return coef[::-1]

# IMPLEMENTAÇÃO DO MÉTODO DE AJUSTE EXPONENCIAL (y = a^e^bx)
def ajuste_exponencial(x, y):
    soma_ln_y, ln_y = logaritmo_natural(y)
    A = np.array([[produtoSimples(x, x), acumulo(x)], [acumulo(x), len(x)]])
    b = np.array([produtoSimples(x, ln_y), soma_ln_y])
    sol = np.linalg.solve(A, b)
    a = e**sol[1]
    b = sol[0]
    return a, b

# APLICAÇÃO DE TODOS OS MÉTODOS DE AJUSTE DE CURVAS
def calcular_modelos(x, y):
    a1, b1 = ajuste_linear(x, y)
    a2, b2, c2 = ajuste_poli2(x, y)
    a3, b3, c3, d3 = ajuste_poli3(x, y)
    a4, b4, c4, d4, e4 = ajuste_poli4(x, y)
    ae, be = ajuste_exponencial(x, y)

    y1 = a1 * x + b1
    y2 = a2 * x**2 + b2 * x + c2
    y3 = a3 * x**3 + b3 * x**2 + c3 * x + d3
    y4 = a4 * x**4 + b4 * x**3 + c4 * x**2 + d4 * x + e4
    ye = ae * np.exp(be * x)

    sqt = erro_total(y)
    n = len(x)

    erros = [erro_medio(erro_residual(y, y1), n), erro_medio(erro_residual(y, y2), n),
             erro_medio(erro_residual(y, y3), n), erro_medio(erro_residual(y, y4), n),
             erro_medio(erro_residual(y, ye), n)]
    
    rqs = [r2(sqt, erro_residual(y, y1)), r2(sqt, erro_residual(y, y2)),
           r2(sqt, erro_residual(y, y3)), r2(sqt, erro_residual(y, y4)),
           r2(sqt, erro_residual(y, ye))]

    eqs = [f"y = {a1:.4f}x + {b1:.4f}",
           f"y = {a2:.4f}x^2 + {b2:.4f}x + {c2:.4f}",
           f"y = {a3:.4f}x^3 + {b3:.4f}x^2 + {c3:.4f}x + {d3:.4f}",
           f"y = {a4:.4f}x^4 + {b4:.4f}x^3 + {c4:.4f}x^2 + {d4:.4f}x + {e4:.4f}",
           f"y = {ae:.4f} * e^({be:.4f}x)"]
    
    return eqs, rqs, erros


# GRÁFICOS DE TODOS OS AJUSTES DE CURVA RESOLVIDOS
def gerar_graficos_ajustes(x, y):
    modelos = ['Linear', 'Polinomial 2º', 'Polinomial 3º', 'Polinomial 4º', 'Exponencial']
    nomes_arquivos = [
        'ajuste_linear.png',
        'ajuste_poli2.png',
        'ajuste_poli3.png',
        'ajuste_poli4.png',
        'ajuste_exp.png'
    ]

    x_continuo = np.linspace(min(x), max(x), 200)

    a1, b1 = ajuste_linear(x, y)
    y1_continua = a1 * x_continuo + b1

    a2, b2, c2 = ajuste_poli2(x, y)
    y2_continua = a2 * x_continuo**2 + b2 * x_continuo + c2

    a3, b3, c3, d3 = ajuste_poli3(x, y)
    y3_continua = a3 * x_continuo**3 + b3 * x_continuo**2 + c3 * x_continuo + d3

    a4, b4, c4, d4, e4 = ajuste_poli4(x, y)
    y4_continua = a4 * x_continuo**4 + b4 * x_continuo**3 + c4 * x_continuo**2 + d4 * x_continuo + e4

    ae, be = ajuste_exponencial(x, y)
    y5_continua = ae * np.exp(be * x_continuo)

    curvas_continuas = [y1_continua, y2_continua, y3_continua, y4_continua, y5_continua]

    for i in range(5):
        salvar_grafico(x, y, x_continuo, curvas_continuas[i], f'Ajuste {modelos[i]}', nomes_arquivos[i])


    plt.figure(figsize=(10, 6))
    plt.scatter(x, y, color='black', label='Dados observados')
    for i in range(5):
        plt.plot(x_continuo, curvas_continuas[i], label=f'{modelos[i]}')
    plt.xlabel('Tempo (anos)')
    plt.ylabel('População (milhares)')
    plt.title('Ajustes das funções')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig('todos_ajustes.png')
    plt.close()

# FUNÇÃO PARA GERAR E SALVAR OS GRÁFICOS
def salvar_grafico(x, y, x_continuo, y_continua, titulo, filename):
    plt.figure(figsize=(8,5))
    plt.scatter(x, y, color='black', label='Dados observados')
    plt.plot(x_continuo, y_continua, label=titulo, color='red')
    plt.xlabel('Tempo (anos)')
    plt.ylabel('População (milhares)')
    plt.title(titulo)
    plt.legend()
    plt.grid(True)
    plt.savefig(filename)
    plt.close()

# GRÁFICO DOS ERROS OBTIDOS
def grafico_erro(modelos, erros):
    fig, ax = plt.subplots()
    barras = ax.bar(modelos, erros, color='blue')
    ax.bar_label(barras, fmt='%.2f', padding=3)

    ax.set_title('Erro Médio Quadrático')
    ax.set_ylabel('Erro')
    ax.grid(True, axis='y')
    plt.tight_layout()
    plt.savefig('erros_mq.png')
    plt.show()
    plt.close()


# GRAFICO PARA COEFICIENTES DE DETERMINAÇÃO
def graficos_r2(modelos, rqs):
    fig, ax = plt.subplots()
    barras = ax.bar(modelos, rqs, color='seagreen')
    ax.bar_label(barras, fmt='%.4f', padding=3)

    ax.set_ylim(0, 1.05)
    ax.set_title('Coeficiente de Determinação R²')
    ax.set_ylabel('R²')
    ax.grid(True, axis='y')
    plt.tight_layout()
    plt.savefig('coef_r2.png')
    plt.show()
    plt.close()

# MENU
def main():
    os.system("cls") 

    x = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
    y = np.array([10, 12.5 ,15.6 ,19.5 ,24.4 ,30.5 ,38.1 ,47.6 ,59.5 ,74.4])
    modelos = ['Linear', 'Polinomial 2º', 'Polinomial 3º', 'Polinomial 4º', 'Exponencial']

    print("\n===== TABELA INICIAL DE DADOS =====")
    dados = list(zip(x, y))
    print(tabulate(dados, headers=["Tempo (anos)", "População (milhares)"], tablefmt="fancy_grid"))

    while True:
        print("\n===== TRABALHO 5 - AJUSTE DE CURVAS =====")
        print("[1] Calcular ajustes")
        print("[2] Comparar coeficientes de determinação R²")
        print("[3] Comparar erros quadráticos médios")
        print("[4] Gerar gráficos dos ajustes")
        print("[5] Sair")
        op = input("--> ")

        if op == '1':
            os.system("cls")
            eqs, rqs, errs = calcular_modelos(x, y)
            tabela = list(zip(modelos, eqs, rqs, errs))
            print("\nEquações Ajustadas:")
            print(tabulate(tabela, headers=["Modelo", "Equação", "R²", "EMQ"], tablefmt="fancy_grid", floatfmt=".4f"))

        elif op == '2':
            os.system("cls")
            _, rqs, _ = calcular_modelos(x, y)
            tabela = list(zip(modelos, rqs))
            print("\nCoeficientes de Determinação R²:")
            print(tabulate(tabela, headers=["Modelo", "R²"], tablefmt="fancy_grid", floatfmt=".4f"))
            graficos_r2(modelos, rqs)

        elif op == '3':
            os.system("cls")
            _, _, errs = calcular_modelos(x, y)
            tabela = list(zip(modelos, errs))
            print("\nErros Quadráticos Médios:")
            print(tabulate(tabela, headers=["Modelo", "EMQ"], tablefmt="fancy_grid", floatfmt=".4f"))
            grafico_erro(modelos, errs)

        elif op == '4':
            os.system("cls")
            gerar_graficos_ajustes(x, y)
            print("\nGráficos dos ajustes gerados e salvos com sucesso!")

        elif op == '5':
            os.system("cls")
            print("Encerrando...")
            break

        else:
            print("Opção inválida. Tente novamente.")


if __name__ == "__main__":
    main()