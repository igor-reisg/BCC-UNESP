import numpy as np
import math

# VERIFICAÇÃO SE MATRIZ É QUADRADA
def quadrada(matriz):
    return matriz.shape[0] == matriz.shape[1]

# VERIFICAÇÃO SE MATRIZ POSSUI PIVOS NÃO NULOS
def temPivos(matriz):
    return all(matriz[i, i] != 0 for i in range(len(matriz)))

# VERIFICAÇÃO SE MATRIZ É INVERSIVEL
def temInversa(matriz):
    return np.linalg.det(matriz) != 0

# VERIFICAÇÃO SE MENORES PRINCIPAIS SÃO NÃO NULOS
def menoresPrincipais(matriz, positivos=False):
    for i in range(1, len(matriz) + 1):
        determinante = np.linalg.det(matriz[:i, :i])
        if positivos and determinante <= 0:
            return False
        if not positivos and determinante == 0:
            return False
    return True

# VERIFICAÇÃO SE MATRIZ É SIMÉTRICA
def simetrica(matriz):
    return np.allclose(matriz, matriz.T)

# VERIFICAÇÃO SE MATRIZ É DIAGONAL DOMINANTE POR LINHAS
def diagonalDominanteLinhas(matriz):
    for i in range(len(matriz)):
        soma = sum(abs(matriz[i, j]) for j in range(len(matriz)) if j != i)
        if abs(matriz[i, i]) <= soma:
            return False
    return True

# VERIFICAÇÃO SE MATRIZ É DIAGONAL DOMINANTE POR COLUNAS
def diagonalDominanteColunas(matriz):
    for j in range(len(matriz)):
        soma = sum(abs(matriz[i, j]) for i in range(len(matriz)) if i != j)
        if abs(matriz[j, j]) <= soma:
            return False
    return True

# VERIFICAÇÃO DO CRITÉRIO DE SASSENFELD
def criterioSassenfeld(matriz):
    n = len(matriz)
    beta = np.zeros(n)
    for i in range(n):
        soma = sum(abs(matriz[i, j]) * beta[j] for j in range(i)) + sum(abs(matriz[i, j]) for j in range(i + 1, n))
        beta[i] = soma / abs(matriz[i, i])
    return np.all(beta < 1)

# Método de Gauss Compacto
def metodoGaussCompacto(matriz):
    if not (quadrada(matriz) and temPivos(matriz) and temInversa(matriz)):
        return False, None, None

    n = len(matriz)
    L = np.eye(n)
    U = matriz.copy().astype(float)

    for i in range(n):
        for j in range(i + 1, n):
            fator = U[j, i] / U[i, i]
            L[j, i] = fator
            U[j, i:] -= fator * U[i, i:]

    return True, L, U

# Método de Gauss-Jordan
def metodoGaussJordan(matriz, termos):
    if not (quadrada(matriz) and temPivos(matriz) and temInversa(matriz)):
        return False, None

    n = len(matriz)
    termos = termos.reshape(-1, 1)
    estendida = np.hstack((matriz.astype(float), termos.astype(float)))

    for i in range(n):
        estendida[i] = estendida[i] / estendida[i, i]
        for j in range(n):
            if i != j:
                estendida[j] -= estendida[j, i] * estendida[i]

    return True, estendida[:, -1]

# Método de Decomposição LU
def metodoDecomposicaoLU(matriz):
    if not (quadrada(matriz) and menoresPrincipais(matriz)):
        return False, None, None

    n = len(matriz)
    L = np.eye(n)
    U = np.zeros((n, n))

    for i in range(n):
        for j in range(i, n):
            U[i, j] = matriz[i, j] - sum(L[i, k] * U[k, j] for k in range(i))
        for j in range(i + 1, n):
            L[j, i] = (matriz[j, i] - sum(L[j, k] * U[k, i] for k in range(i))) / U[i, i]

    return True, L, U

# Método de Cholesky
def metodoCholesky(matriz):
    if not (simetrica(matriz) and menoresPrincipais(matriz, positivos=True)):
        return False, None

    n = len(matriz)
    L = np.zeros((n, n))

    for i in range(n):
        for j in range(i + 1):
            soma = sum(L[i, k] * L[j, k] for k in range(j))
            if i == j:
                L[i, j] = math.sqrt(matriz[i, i] - soma)
            else:
                L[i, j] = (matriz[i, j] - soma) / L[j, j]

    return True, L

# Método de Jacobi
def metodoJacobi(matriz, termos):
    if not (diagonalDominanteLinhas(matriz) and diagonalDominanteColunas(matriz)):
        return False, None, None, None

    n = len(matriz)
    max_iter = 50
    tol = 1e-5
    x = np.zeros(n)
    historico = []

    for _ in range(max_iter):
        novo_x = np.zeros(n)
        for i in range(n):
            soma = sum(matriz[i, j] * x[j] for j in range(n) if j != i)
            novo_x[i] = (termos[i] - soma) / matriz[i, i]

        erro = np.linalg.norm(novo_x - x, ord=np.inf) / np.linalg.norm(novo_x, ord=np.inf)
        x = novo_x
        historico.append(x.copy())

        if erro < tol:
            return True, x, len(historico), np.array(historico), erro

    erro = np.linalg.norm(novo_x - x, ord=np.inf) / np.linalg.norm(novo_x, ord=np.inf)
    return False, x, max_iter, np.array(historico), erro

# Método de Gauss-Seidel
def metodoGaussSeidel(matriz, termos):
    if not (diagonalDominanteLinhas(matriz) and criterioSassenfeld(matriz)):
        return False, None, None, None

    n = len(matriz)
    max_iter = 50
    tol = 1e-5
    x = np.zeros(n)
    historico = []

    for _ in range(max_iter):
        x_ant = x.copy()
        for i in range(n):
            soma1 = sum(matriz[i, j] * x[j] for j in range(i))
            soma2 = sum(matriz[i, j] * x_ant[j] for j in range(i + 1, n))
            x[i] = (termos[i] - soma1 - soma2) / matriz[i, i]

        erro = np.linalg.norm(x - x_ant, ord=np.inf) / np.linalg.norm(x, ord=np.inf)
        historico.append(x.copy())

        if erro < tol:
            return True, x, len(historico), np.array(historico), erro

    erro = np.linalg.norm(x - x_ant, ord=np.inf) / np.linalg.norm(x, ord=np.inf)
    return False, x, max_iter, np.array(historico), erro

# SOLUÇÃO DOS SISTEMAS LINEARES
def solucao(L, U, b, ok=True):
    if not ok:
        return None
    n = len(b)
    
    # Substituição direta para Ly = b
    y = np.zeros(n)
    for i in range(n):
        y[i] = b[i] - sum(L[i][j] * y[j] for j in range(i))
    
    # Substituição reversa para Ux = y
    x = np.zeros(n)
    for i in reversed(range(n)):
        x[i] = (y[i] - sum(U[i][j] * x[j] for j in range(i + 1, n))) / U[i][i]
    
    return x
