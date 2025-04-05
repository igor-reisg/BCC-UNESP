#include <stdio.h>

int main() { 
    int i, j, m, n, igual = 1, encontrado = 0, seq[100];
    
    printf("Digite o tamanho da sequencia (max = 100): ");
    scanf("%d", &n);

    printf("Digite os elementos da sequencia: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }


    for (m = 1; m <= n / 2; m++) { 
        for (i = 0; i <= n - 2 * m; i++) { 
            
            for (j = 0; j < m; j++) {
                if (seq[i + j] != seq[i + m + j]) {
                    igual = 0;
                    break;
                }
            }
            
            if (igual) {
                printf("i = %d e m = %d\n", i + 1, m); 
                encontrado = 1;
                break;
            }
        }
        if (encontrado) {
            break;
        }
    }
    
    if (!encontrado) {
        printf("Nao existem dois segmentos consecutivos iguais na sequencia.\n");
    }
}
