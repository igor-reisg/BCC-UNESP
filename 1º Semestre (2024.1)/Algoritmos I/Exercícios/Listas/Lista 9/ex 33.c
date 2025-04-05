#include <stdio.h>

int main() {
    int m, n, i, j;
    float matriz[20][20], soma = 0;

    printf("Digite a ordem da matriz (m x n): ");
    scanf("%d %d", &m, &n);

    printf("\nDigite os elementos da matriz:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("\nDigite o índice da linha (i): ");
    scanf("%d", &i);

    if (i < 0 || i >= m) {
        printf("\nÍndice da linha inválido!\n");
    }

    for (j = 0; j < n; j++) {
        soma += matriz[i][j];
    }

    printf("\nSoma da %da linha: %.2f\n", i + 1, soma);

return 0;
}