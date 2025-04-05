#include <stdio.h>

int main() {
    int vet[50], n, aux, sorted;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("vet[%d] = ", i);
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < n; i++) {
        sorted = 0;
        for (int j = i + 1; j < n; j++) {
            if (vet[i] > vet[j]) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
                sorted = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
}