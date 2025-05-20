import sympy as sp
import math

def interLagrange(pontos_x, pontos_y):
    itens = len(pontos_x)
    polinomio = 0
    x = sp.Symbol('x')

    for i in range(itens):
        li = 1
        for j in range(itens):
            if i is not j:
                li *= (x - pontos_x[j]) / (pontos_x[i] - pontos_x[j])
        
        polinomio += pontos_y[i] * li

    return sp.expand(polinomio).evalf(4)

def interNewton(pontos_x, pontos_y):
    n = len(pontos_x)
    tabela = []
    polinomio = 0
    x = sp.Symbol('x')

    for _ in range(n):
        linha = [0] * n
        tabela.append(linha)

    for i in range(n):
        tabela[i][0] = pontos_y[i]

    for j in range(1, n):
        for i in range(n - j):
            num = tabela[i + 1][j - 1] - tabela[i][j - 1]
            den = pontos_x[i + j] - pontos_x[i]
            tabela[i][j] = num / den

    polinomio = tabela[0][0]
    prod = 1

    for i in range(1, n):
        prod *= (x - pontos_x[i - 1])
        polinomio += tabela[0][i] * prod

    return sp.expand(polinomio).evalf(4)

def condicaoNewtonGregory(pontos_x):
    n = len(pontos_x)
    h = abs(pontos_x[1] - pontos_x[0])

    for i in range(1, n - 1):
        if abs(pontos_x[i + 1] - pontos_x[i]) != h:
            return False, 0
        
    return True, h

def interNewtonGregory(pontos_x, pontos_y, h):
    n = len(pontos_x)
    x = sp.Symbol('x')
    tabela = []
    polinomio = 0

    for _ in range(n):
        linha = [0] * n
        tabela.append(linha)

    for i in range(n):
        tabela[i][0] = pontos_y[i]

    for j in range(1, n):
        for i in range(n - j):
            tabela[i][j] = tabela[i + 1][j - 1] - tabela[i][j - 1]

    s = (x - pontos_x[0]) / h
    polinomio = tabela[0][0]
    prod = 1

    for i in range(1, n):
        prod *= (s - (i - 1))
        polinomio += tabela[0][i] / math.factorial(i) * prod

    return sp.expand(polinomio).evalf(4)

def solvePolinomio(polinomio, val, var = 'x'):
    x = sp.Symbol(var)
    res = polinomio.subs(x, val).evalf()

    return res