import os
import matplotlib.pyplot as plt
from tabulate import tabulate
import funcoes
import numpy as np

#Valores calculados usando o geogebra
derivadas_regressao = np.array([
    76.3073788546256, 76.1573788546256, 76.0573788546256,
    75.9073788546256, 75.8073788546256, 75.6573788546256
])

# Tabela com as velocidades calculadas pelos métodos e pela regressão
def imprimir_tabela_resultados(tempos, posicoes, vp, vr, vc):
    headers = ["Tempo (s)", "Posição (m)", "Progressiva", "Regressiva", "Central", "Função Regressão"]
    tabela = []

    for i in range(len(tempos)):
        p = f"{vp[i]:.2f}" if vp[i] is not None else "-"
        r = f"{vr[i]:.2f}" if vr[i] is not None else "-"
        c = f"{vc[i]:.2f}" if vc[i] is not None else "-"
        der = f"{derivadas_regressao[i]:.2f}" if derivadas_regressao[i] is not None else "-"
        tabela.append([tempos[i], posicoes[i], p, r, c, der])

    print("\nTabela de Velocidades Calculadas:")
    print(tabulate(tabela, headers=headers, tablefmt="fancy_grid"))

# Tabela com os erros absolutos entre os métodos e a regressão
def imprimir_tabela_erros(tempos, posicoes, vp, vr, vc):
    headers = ["Tempo (s)", "Posição (m)", "Erro Prog.", "Erro Regr.", "Erro Cent."]
    tabela = []

    erros_p, erros_r, erros_c = funcoes.calcular_erros(vp, vr, vc, derivadas_regressao)

    for i in range(len(tempos)):
        ep = erros_p[i]
        er = erros_r[i]
        ec = erros_c[i]

        tabela.append([
            tempos[i], posicoes[i],
            f"{ep:.2f}" if ep is not None else "-",
            f"{er:.2f}" if er is not None else "-",
            f"{ec:.2f}" if ec is not None else "-",
        ])

    print("\nTabela de Erros (Diferença para a média entre métodos):")
    print(tabulate(tabela, headers=headers, tablefmt="fancy_grid"))
    return erros_p, erros_r, erros_c

# Gera e salva o gráfico das velocidades calculadas
def gerar_grafico_velocidades(tempos, vp, vr, vc):
    plt.figure(figsize=(10, 5))
    plt.plot(tempos, vp, label='Progressiva', linestyle='--', marker='o', color="red")
    plt.plot(tempos, vr, label='Regressiva', linestyle='-', marker='^', color="green")
    plt.plot(tempos, vc, label='Central', linestyle='-.', marker='s', color="blue")
    plt.plot(tempos, derivadas_regressao, label="Derivadas Regressão", linestyle=':', marker='8', color="orange")
    plt.xlabel("Tempo (s)")
    plt.ylabel("Velocidade (m/s)")
    plt.title("Comparação dos Métodos de Diferença Finita")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    nome_arquivo = "grafico_velocidades.png"
    plt.savefig(nome_arquivo)
    plt.close()
    print(f"\nGráfico de velocidades salvo como: {nome_arquivo}")

# Gera e salva o gráfico dos erros absolutos por método
def gerar_grafico_erros(tempos, erros_p, erros_r, erros_c):
    plt.figure(figsize=(10, 5))
    plt.plot(tempos, erros_p, 'o-', label='Erro Progressiva')
    plt.plot(tempos, erros_r, 's-', label='Erro Regressiva')
    plt.plot(tempos, erros_c, '^-', label='Erro Central')
    plt.xlabel("Tempo (s)")
    plt.ylabel("Erro Absoluto (m/s)")
    plt.title("Comparação dos Erros por Método")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    nome_arquivo = "grafico_erros.png"
    plt.savefig(nome_arquivo)
    plt.close()
    print(f"\nGráfico de erros salvo como: {nome_arquivo}")

# Função Main c/ Menu
def main():
    tempos = [0, 3, 5, 8, 10, 13]
    posicoes = [0, 225, 383, 623, 742, 993]

    continuar = 's'
    while continuar == 's':
        os.system("cls")
        print("\n===== TRABALHO 2 - DIFERENCIAÇÃO NUMÉRICA =====")
        print("\nEscolha uma das opções abaixo:\n")
        print("[1] Calcular velocidades")
        print("[2] Calcular erros")
        print("[3] Gerar gráficos comparativo entre métodos e erros")
        print("[4] Sair")
        opcao = input("--> ").strip()

        if opcao == '1':
            os.system("cls")
            vp = funcoes.df_progressiva(tempos, posicoes)
            vr = funcoes.df_regressiva(tempos, posicoes)
            vc = funcoes.df_central(tempos, posicoes)
            imprimir_tabela_resultados(tempos, posicoes, vp, vr, vc)

        elif opcao == '2':
            os.system("cls")
            vp = funcoes.df_progressiva(tempos, posicoes)
            vr = funcoes.df_regressiva(tempos, posicoes)
            vc = funcoes.df_central(tempos, posicoes)
            imprimir_tabela_erros(tempos, posicoes, vp, vr, vc)

        elif opcao == '3':
            os.system("cls")
            vp = funcoes.df_progressiva(tempos, posicoes)
            vr = funcoes.df_regressiva(tempos, posicoes)
            vc = funcoes.df_central(tempos, posicoes)
            gerar_grafico_velocidades(tempos, vp, vr, vc)
            erros_p, erros_r, erros_c = funcoes.calcular_erros(vp, vr, vc, derivadas_regressao)
            gerar_grafico_erros(tempos, erros_p, erros_r, erros_c)

        elif opcao == '4':
            print("Saindo...")
            break
        else:
            print("\nOpção inválida.")

        continuar = input("\nDeseja continuar? (s/n) ").strip().lower()
        if continuar != 's':
            print("\nFinalizando o programa...\n")

if __name__ == "__main__":
    main()
