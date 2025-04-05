#include <stdio.h>
#define lin 20
#define col 20

int main() {

    int cont = 1, m, n, mat[lin][col], i, j;

    do {

        int somalin[lin] = {0}, soma = 0;

        printf("Digite a quantidade de linhas da tabela: ");
        scanf("%d", &m);

        printf("Digite a quantidade de colunas da tabela: ");
        scanf("%d", &n);

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("valor[%d][%d] = ", i, j);
                scanf("%d", &mat[i][j]);
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                somalin[i] += mat[i][j];
                soma += mat[i][j];
            }
        }

        printf("Soma de todos os elementos da tabela: %d\n", soma);

        for (i = 0; i < m; i++) {
                printf("Soma linha %d: %d\n", i, somalin[i]);
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