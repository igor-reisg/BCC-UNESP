#include <stdio.h>

void sort(int vet[], int tam);

int main() {
    int vet[50], i, tam;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    for (i = 0; i < tam; i++) {
        printf("vet[%d] = ", i);
        scanf("%d", &vet[i]);
    }

    printf("VETOR DADO:\n");
    for (i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    sort(vet, tam);

    printf("VETOR ORDENADO:\n");
    for (i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void sort(int vet[], int tam) {
    int i, j, aux;


    for (i = 0; i < tam - 1; i++) {
        for (j = i + 1; j < tam; j++) {
            if (vet[i] > vet[j]) {
                aux = vet[j];
                vet[j] = vet[i];
                vet[i] = aux;
            }
        }
    }
}
