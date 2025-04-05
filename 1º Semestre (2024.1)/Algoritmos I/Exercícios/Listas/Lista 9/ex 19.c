#include <stdio.h>
#define lin 20
#define col 30

int main() {

    int cont = 1, n, m, mat1[lin][col], mat2[lin][col + 1], i, j, prod[lin];

    do {

        printf("Digite a quantidade de linhas e colunas: ");
        scanf("%d %d", &m, &n);

        for (i = 0; i < m; i++) {

            prod[i] = 1;
            for (j = 0; j < n; j++) {
                printf("mat[%d][%d] = ", i, j);
                scanf("%d", &mat1[i][j]);
                prod[i] *= mat1[i][j];
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n + 1; j++) {
                mat2[i][j] = mat1[i][j];
                
                if (j == n) {
                    mat2[i][j] = prod[i];
                }
            }
        }

        printf("MATRIZ B\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n + 1; j++) {
                printf("%3d ", mat2[i][j]);
            }
            printf("\n");
        }

        printf("Executar novamente? (1- Sim | 2-Nao) ");
        scanf("%d", &cont);

        while (cont != 1 && cont != 2) {
            printf("Valor invalido. Digite novamente: ");
            scanf("%d", &cont);
        }
    }
    while (cont == 1);
}