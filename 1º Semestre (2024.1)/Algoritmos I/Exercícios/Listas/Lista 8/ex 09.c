#include <stdio.h>

int main () {

    int continuar = 1, vet1[100], vet2[100], i, tam;

    do {
        printf("Digite o tamanho dos 2 vetores: ");
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

        printf("Vetores somados:\n");
        for (i = 0; i < tam; i++) {
            printf("%3d |", vet1[i]+vet2[i]);
        }

        printf("\nExecutar novamente? (1-Sim | 2-Nao) ");
        scanf("%d", &continuar);

        while (continuar != 1 && continuar != 2) {
            printf("Valor invalido. Digite novamente: ");
            scanf("%d", &continuar);
        }
    }
    while (continuar == 1);
}