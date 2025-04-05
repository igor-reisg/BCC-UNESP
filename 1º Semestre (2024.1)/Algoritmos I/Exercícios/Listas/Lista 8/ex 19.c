#include <stdio.h>

int main () {

    int continuar = 1, vet[20], i, tam, temp, j;

    do {
        printf("Digite o tamanho do vetor (maximo 20): ");
        scanf("%d", &tam);

        for (i = 0; i < tam; i++) {
            printf("vet[%d] = ", i);
            scanf("%d", &vet[i]);
        }

        printf("Vetor:\n");
        for (i = 0; i < tam; i++) {
            printf("%3d |", vet[i]);
        }

        for (i = 0; i < tam; i++) {
            for (j = i + 1; j < tam; j++) {
                if (vet[i] > vet[j]) {
                    temp = vet[i];
                    vet[i] = vet[j];
                    vet[j] = temp;
                }
            }
        }

        printf("\nVetor ordenado:\n");
        for (i = 0; i < tam; i++) {
            printf("%3d |", vet[i]);
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