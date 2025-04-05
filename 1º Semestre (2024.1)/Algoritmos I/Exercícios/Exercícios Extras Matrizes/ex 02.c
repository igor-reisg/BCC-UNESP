#include <stdio.h>
#define lin 100
#define col 100

int main() {

    int i, j, m, n, continuar = 1;
    float mat[lin][col], soma[lin];
    
    do {
        printf("Digite a quantidade de linhas da matriz (max = 100): ");
        scanf("%d", &m);
        
        printf("Digite a quantidade de colunas da matriz (max = 100): ");
        scanf("%d", &n);
        
        printf("Digite os elementos da matriz:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("matriz[%d][%d] = ", i, j);
                scanf("%f", &mat[i][j]);
                soma[i] += mat[i][j];
            }
        }
        printf("\nMATRIZ LIDA:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%4.1f |", mat[i][j]);
            }
            printf("\n");
        }
        
        for (i = 0; i < m; i++) {
            printf("Soma (linha %d) = %.1f\n", i, soma[i]);
        }
        
        printf("\nExecutar novamente? (1-Sim | 2-Nao) ");
        scanf("%d", &continuar);
        
        while (continuar != 1 && continuar != 2) {
            printf("Numero invalido. Digite novamente: ");
            scanf("%d", &continuar);
        }
    }
    while (continuar == 1);
}
