import math
import time

# Implementação do Método da Bisseção
def metBissecao(f, a, b, erro):
    inicio = time.perf_counter()
    
    if f(a) * f(b) >= 0:
        print("\nMétodo da Bisseção: Os valores de a e b não satisfazem f(a) * f(b) < 0\n")
        return None, 0, 0.0, []

    maxIteracoes = 10000
    i = 0
    valores_x = []
    
    while True:
        x = (a + b) / 2
        fx = f(x)
    
        valores_x.append(x)

        if i >= maxIteracoes:
            print("\nNão convergente: quantidade máxima de iterações atingida\n")
            return None, i, (time.perf_counter() - inicio), valores_x
        
        if abs(fx) <= erro or abs(b - a) <= erro:
            tempo = (time.perf_counter() - inicio)
            return x, i, tempo, valores_x

        if f(a) * fx < 0:
            b = x
        else:
            a = x

        i += 1

# Implementação do Método da Falsa Posição
def metFalsaPosicao(f, a, b, erro):
    inicio = time.perf_counter()

    if f(a) * f(b) >= 0:
        print("Método da Falsa Posição: Os valores de a e b não satisfazem f(a) * f(b) < 0\n")
        return None, 0, 0.0, []

    maxIteracoes = 10000
    i = 0
    valores_x = []
    
    while True:
        x = (a * f(b) - b * f(a)) / (f(b) - f(a))
        fx = f(x)
        
        valores_x.append(x)

        if i >= maxIteracoes:
            print("Não convergente: quantidade máxima de iterações atingida\n")
            return None, i, (time.perf_counter() - inicio), valores_x

        if abs(fx) <= erro or abs(b - a) <= erro:
            tempo = (time.perf_counter() - inicio)
            return x, i, tempo, valores_x

        if f(a) * fx < 0:
            b = x
        else:
            a = x

        i += 1

# Implementação do Método de Newton
def metNewton(f, df, x0, erro):
    inicio = time.perf_counter()
    maxIteracoes = 10000
    i = 0
    
    valores_x = [x0]
    
    while True:
        if df(x0) == 0:
            print("Erro matemático: derivada nula\n")
            return None, i, (time.perf_counter() - inicio), valores_x

        x1 = x0 - f(x0) / df(x0)
        i += 1
        
        valores_x.append(x1)

        if i >= maxIteracoes:
            print("Não convergente: quantidade máxima de iterações atingida\n")
            return None, i, (time.perf_counter() - inicio), valores_x

        if abs(f(x1)) <= erro:
            tempo = (time.perf_counter() - inicio)
            return x1, i, tempo, valores_x
        else:
            x0 = x1

# Função do Problema 1
def funcaoEx1(p):
    return 5 * p - 100

# Derivada da função do Problema 1
def dfEx1(p):
    return 5

# Função do Problema 2
def funcaoEx2(v):
    Is = 1e-12
    n = 1
    vt = 0.025
    i = 0.010
    return Is * (math.exp(v / (n * vt)) - 1) - i

# Derivada da função do Problema 2
def dfEx2(v):
    Is = 1e-12
    n = 1
    vt = 0.025
    return (Is / (n * vt)) * math.exp(v / (n * vt))

# Função do Problema 3
def funcaoEx3(x):
    ka = 1 * 10e-5
    c = 0.1

    return x**2 / (c - x) - ka

# Derivada da função do Problema 3
def dfEx3(x):
    c = 0.1
    return (2 * x * (c - x) + x ** 2) / ((c - x) ** 2)

# Função do Problema 4
def funcaoEx4(epsilon, sigma, r):
    termo1 = (sigma / r) ** 13
    termo2 = (sigma / r) ** 7

    return 24 * epsilon * (2 * termo1 - termo2)

# Derivada da função do Problema 4
def dfEx4(epsilon, sigma, r):
    return 24 * epsilon * (-26 * (sigma ** 13) / (r ** 14) + 7 * (sigma ** 7) / (r ** 8))

# Função do Problema 5
def funcaoEx5(k):
    return k - 1 - math.exp(-k)

# Derivada da função do Problema 5
def dfEx5(k):
    return math.exp(-k) + 1