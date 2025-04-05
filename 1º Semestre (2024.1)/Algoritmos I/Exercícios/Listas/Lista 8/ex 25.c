#include <stdio.h>

int main() {

    int T1, T2, i, j, k, continuar = 1;
    float A[100], B[100], C[200];
    
    do {
        printf("Digite o tamanho do vetor A: ");
        scanf("%d", &T1);
        printf("Digite o tamanho do vetor B: ");
        scanf("%d", &T2);
        
        printf("Digite os elementos do vetor A:\n");
        for (i = 0; i < T1; i++) {
            scanf("%f", &A[i]);
        }
        
        printf("Digite os elementos do vetor B:\n");
        for (i = 0; i < T2; i++) {
            scanf("%f", &B[i]);
        }

        i = 0, j = 0, k = 0;

        while (i < T1 && j < T2) {
            C[k++] = A[i++];
            C[k++] = B[j++];
        }
        
        while (i < T1) {
            C[k++] = A[i++];
        }
        
        while (j < T2) {
            C[k++] = B[j++];
        }
        
        printf("Vetor C intercalado:\n");
        for (i = 0; i < T1 + T2; i++) {
            printf(" %.1f |", C[i]);
        }
        printf("\n");

        printf("Relizar novamente? (1-Sim | 2-Nao) ");
        scanf("%d", &continuar);

        while (continuar != 1 && continuar != 2) {
            printf("Valor invalido. Digite novamente: ");
            scanf("%d", &continuar);
        }
    }
    while (continuar == 1);

    return 0;
}
