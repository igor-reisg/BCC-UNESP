#include <stdio.h>
#define lin 100

int main() {

    int i, j, m, n, continuar = 1;
    int mat[lin][lin], soma = 0;
    
    do {
        printf("Digite a ordem da matriz (max = 100): ");
        scanf("%d", &n);
        
        printf("Digite os elementos da matriz:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("matriz[%d][%d] = ", i, j);
                scanf("%d", &mat[i][j]);
            }
        }
        printf("\nMATRIZ LIDA:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%2.1d |", mat[i][j]);
            }
            printf("\n");
        }
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i >= j) {
                    soma += mat[i][j];
                }
            }
        }
        printf("soma = %d\n", soma);
        
        printf("\nExecutar novamente? (1-Sim | 2-Nao) ");
        scanf("%d", &continuar);
        
        while (continuar != 1 && continuar != 2) {
            printf("Numero invalido. Digite novamente: ");
            scanf("%d", &continuar);
        }
        soma = 0;
    }
    while (continuar == 1);
}
