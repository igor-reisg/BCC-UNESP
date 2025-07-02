
# Implementação do método de Diferença Finita Progressiva
def df_progressiva(x, y):
    n = len(x)
    resultado = []

    for i in range(n):
        if i < n - 1:
            h = x[i + 1] - x[i]
            resultado.append((y[i + 1] - y[i]) / h)
        else:
            resultado.append(None)
    
    return resultado

# Implementação do método de Diferença Finita Regressiva
def df_regressiva(x, y):
    n = len(x)
    resultado = []

    for i in range(n):
        if i > 0:
            h = x[i] - x[i - 1]
            resultado.append((y[i] - y[i - 1]) / h)
        else:
            resultado.append(None)
    
    return resultado

# Implementação do método de Diferença Finita Central
def df_central(x, y):
    n = len(x)
    resultado = []

    for i in range(n):
        if 0 < i < n - 1:
            h = x[i + 1] - x[i - 1]
            resultado.append((y[i + 1] - y[i - 1]) / h)
        else:
            resultado.append(None)
    
    return resultado

# Calcula os erros absolutos entre os métodos e a derivada real
def calcular_erros(vp, vr, vc, derivadas_regressao):
    erros_p = []
    erros_r = []
    erros_c = []

    for i in range(len(derivadas_regressao)):
        erros_r.append(f"{abs(vr[i] - derivadas_regressao[i]):.6f}" if vr[i] is not None else "-")
        erros_c.append(f"{abs(vc[i] - derivadas_regressao[i]):.6f}" if vc[i] is not None else "-")
        erros_p.append(f"{abs(vp[i] - derivadas_regressao[i]):.6f}" if vp[i] is not None else "-")

    erros_r = [float(v) if v != "-" else None for v in erros_r]
    erros_c = [float(v) if v != "-" else None for v in erros_c]
    erros_p = [float(v) if v != "-" else None for v in erros_p]

    return erros_p, erros_r, erros_c

