#include <stdio.h>

int main() {
    int n, M, i, j;
    double alpha, coef[11], r, q[11];

    printf("Digite o grau do polinomio (max = 10): ");
    scanf("%d", &n);


    printf("Digite os coeficientes do polinomio (do termo constante ao termo de maior grau):\n");
    for (i = 0; i <= n; i++) {
        scanf("%lf", &coef[i]);
    }

    printf("Digite o numero de valores de alpha: ");
    scanf("%d", &M);

    for (i = 0; i < M; i++) {
        printf("Digite o valor de alpha: ");
        scanf("%lf", &alpha);

        r = coef[n];

        for (j = n - 1; j >= 0; j--) {
            q[j] = r;
            r = coef[j] + alpha * r;
        }

        printf("Para alpha = %.2f, q(x) eh: ", alpha);
        for (j = n - 1; j >= 0; j--) {
            printf("%.2f ", q[j]);
        }
        printf("\n");
    }
}