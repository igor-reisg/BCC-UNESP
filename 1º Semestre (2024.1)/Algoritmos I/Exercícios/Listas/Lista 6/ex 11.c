#include <stdio.h>
#include <math.h>

int fat(int n);

int main() {

    double x, soma = 0.0;
    int i, n, sinal = -1;

    printf("Numero de termos da serie: ");
    scanf("%d", &n);

    printf("Valor de x: ");
    scanf("%lf", &x);

    soma = x;

    for (i = 3; i <= n; i += 2) {
        soma += pow(x, i) / (fat(i) * sinal);
        sinal *= -1;
    }

    printf("sen(%.1lf) = %.5lf\n", x, soma);
    printf("sen(%.1lf) = %.5f\n", x, sin(x));
}

int fat(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fat(n - 1);
    }
}