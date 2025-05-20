import funcoes
import time
import matplotlib.pyplot as plt

def opcao1(x, y):
    inicio = time.perf_counter()
    polinomio = funcoes.interLagrange(x, y)
    tempo = time.perf_counter() - inicio
    res = funcoes.solvePolinomio(polinomio, 2.5)

    print(f"\n[1] Interpolação de Lagrange:")
    print(f"Polinomio na forma expandida: {polinomio}")
    print(f"Valor interpolado em x = 2.5: {res:.4f}")
    print(f"Tempo de execução: {tempo:.6f} segundos\n")

    return polinomio, res, tempo

def opcao2(x, y):
    inicio = time.perf_counter()
    polinomio = funcoes.interNewton(x, y)
    tempo = time.perf_counter() - inicio
    res = funcoes.solvePolinomio(polinomio, 2.5)

    print(f"\n[2] Interpolação de Newton:")
    print(f"Polinomio na forma expandida: {polinomio}")
    print(f"Valor interpolado em x = 2.5: {res:.4f}")
    print(f"Tempo de execução: {tempo:.6f} segundos\n")

    return polinomio, res, tempo

def opcao3(x, y):
    flag, h = funcoes.condicaoNewtonGregory(x)
    if not flag:
        print("\nAs diferenças entre todos os pontos não são iguais. Método não aplicável.\n")
        return None, None, None

    inicio = time.perf_counter()
    polinomio = funcoes.interNewtonGregory(x, y, h)
    tempo = time.perf_counter() - inicio
    res = funcoes.solvePolinomio(polinomio, 2.5)

    print(f"\n[3] Interpolação de Newton-Gregory:")
    print(f"Polinômio expandido: {polinomio}")
    print(f"Valor interpolado em x = 2.5: {res:.4f}")
    print(f"Tempo de execução: {tempo:.6f} segundos\n")

    return polinomio, res, tempo

def opcao4(x, y):
    pol_lagrange = funcoes.interLagrange(x, y)
    pol_newton = funcoes.interNewton(x, y)
    _, h = funcoes.condicaoNewtonGregory(x)
    pol_newtongregory = funcoes.interNewtonGregory(x, y, h)

    polinomios = {
        'Lagrange': pol_lagrange,
        'Newton': pol_newton,
        'Newton-Gregory': pol_newtongregory
    }

    cores = {
        'Lagrange': 'red',
        'Newton': 'green',
        'Newton-Gregory': 'blue'
    }

    valores_x = [i * 0.1 for i in range(-10, 61)]
    
    fig, graficos = plt.subplots(1, 3, figsize=(18, 5))

    for i, (metodo, polinomio) in enumerate(polinomios.items()):
        valores_y = [polinomio.subs('x', val).evalf() for val in valores_x]
        graficos[i].plot(valores_x, valores_y, color=cores[metodo], label=metodo)
        graficos[i].plot(x, y, 'ko', label='Pontos experimentais')
        graficos[i].set_title(f'{metodo}')
        graficos[i].set_xlabel('Tempo (s)')
        graficos[i].set_ylabel('Temperatura (°C)')
        graficos[i].grid(True)
        graficos[i].legend()

    plt.tight_layout()
    plt.show()


def main():
    x = [0, 1, 2, 3, 4, 5]
    y = [2.1, 3.8, 5.2, 6.1, 7.8, 8.9]

    continuar = 's'
    while continuar == 's':
        print("\nTRABALHO 4 - MÉTODOS NUMÉRICOS")
        print("\nCom que método deseja resolver o problema:\n")
        print("[1] Interpolação de Lagrange")
        print("[2] Interpolação de Newton")
        print("[3] Interpolação de Newton-Gregory")
        print("[4] Gerar gráficos comparativos entre métodos")
        print("[5] Comparar erro e eficiência dos métodos")
        opcao = int(input("--> "))

        if opcao == 1:
            opcao1(x, y)
        elif opcao == 2:
            opcao2(x, y)
        elif opcao == 3:
            opcao3(x, y)
        elif opcao == 4:
            opcao4(x, y)
        elif opcao == 5:
            _, r1, t1 = opcao1(x, y)
            _, r2, t2 = opcao2(x, y)
            _, r3, t3 = opcao3(x, y)

            print("\n[Comparação de Erros]")
            print(f"Erro entre Lagrange e Newton: {abs(r1 - r2):.6f}")
            print(f"Erro entre Lagrange e Newton-Gregory: {abs(r1 - r3):.6f}")
            print(f"Erro entre Newton e Newton-Gregory: {abs(r2 - r3):.6f}")

            print("\n[Comparação de Eficiência]")
            print(f"Tempos: Lagrange: {t1:.6f}s | Newton: {t2:.6f}s | Newton-Gregory: {t3:.6f}s")
        else:
            print("Opção inválida.")

        continuar = input("\nDeseja continuar? (s/n) ").strip().lower()
        
        if continuar == 'n':
            print("\nFinalizando o programa...\n")

if __name__ == '__main__':
    main()