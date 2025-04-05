#include <stdio.h>

int main() {

    int i, tam, continuar = 1, soma = 0, vet1[100], vet2[100];
    
    do {
    
       printf("Tamanho dos vetores: ");
       scanf("%d", &tam);
        
        for (i = 0; i < tam; i++) {
            printf("vet1[%d] = ", i);
            scanf("%d", &vet1[i]);
        }
        
        printf("\n");
        
        for (i = 0; i < tam; i++) {
            printf("vet2[%d] = ", i);
            scanf("%d", &vet2[i]);
        }
        
        for (i = 0; i < tam; i++) {
            soma += vet1[i] * vet2[i];
        }
        
        printf("Produto escalar: %d", soma);
        
        printf("\nRealizar novamente?  (1- Sim | 2- Nao) ");
        scanf("%d", &continuar);
        
        soma = 0;
    }
    while (continuar == 1);
    
    return 0;
}
