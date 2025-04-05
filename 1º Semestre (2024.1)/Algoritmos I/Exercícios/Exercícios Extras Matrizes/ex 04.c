#include <stdio.h>
#define lin 100

int main() {

    int i, j, m, n, continuar = 1, verifica = 1;
    float mat[lin][lin], soma = 0;
    
    do {
        printf("Digite a ordem da matriz (max = 100): ");
        scanf("%d", &n);
        
        printf("Digite os elementos da matriz:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("matriz[%d][%d] = ", i, j);
                scanf("%f", &mat[i][j]);
            }
        }
        printf("\nMATRIZ LIDA:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%4.1f |", mat[i][j]);
            }
            printf("\n");
        }
        
        for (i = 0; i < n && verifica; i++) {
            for (j = i + 1; j < n && verifica; j++) {
                if (mat[i][j] != mat[j][i]) {
                    verifica = 0;
                }
            }
        }
        
        if (verifica == 1) {
            printf("\nA matriz eh simetrica\n");
        }
        else
            printf("\nA matriz nao eh simetrica\n");
        
        printf("\nExecutar novamente? (1-Sim | 2-Nao) ");
        scanf("%d", &continuar);
        
        while (continuar != 1 && continuar != 2) {
            printf("Numero invalido. Digite novamente: ");
            scanf("%d", &continuar);
        }
        verifica = 0;
    }
    while (continuar == 1);
}
