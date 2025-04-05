#include <stdio.h>
#define lin 20
#define col 20

int main() {

    int cont = 1, m, n, mat1[lin][col], mat2[lin][col], mat3[lin][col], i, j;

    do {

        printf("Digite a quantidade de linhas e colunas da matriz: ");
        scanf("%d %d", &m, &n);

        printf("Matriz 1\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("mat1[%d][%d] = ", i, j);
                scanf("%d", &mat1[i][j]);
            }
        }

        printf("\nMatriz 2\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("mat2[%d][%d] = ", i, j);
                scanf("%d", &mat2[i][j]);
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                mat3[i][j] = mat1[i][j] + mat2[i][j];
            }
        }

        printf("\nMatriz 3 (soma)\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%3d ", mat3[i][j]);
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