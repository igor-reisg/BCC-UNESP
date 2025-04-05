#include <stdio.h>
#define lin 20
#define col 20

int main() {

    int cont = 1, n, mat[lin][col], i, j;

    do {
        int soma = 0;

        printf("Digite a ordem da matriz: ");
        scanf("%d", &n);

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("mat[%d][%d] = ", i, j);
                scanf("%d", &mat[i][j]);
            }
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j <= i; j++) {
                soma += mat[i][j];
            }
        }

        printf("Soma dos elementos abaixo da diagonal principal, incluindo a diagonal principal: %d\n", soma);

        printf("Executar novamente? (1- Sim | 2-Nao) ");
        scanf("%d", &cont);

        while (cont != 1 && cont != 2) {
            printf("Valor invalido. Digite novamente: ");
            scanf("%d", &cont);
        }
    }
    while (cont == 1);
}