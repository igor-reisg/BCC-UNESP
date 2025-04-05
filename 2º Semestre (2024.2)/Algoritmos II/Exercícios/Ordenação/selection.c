#include <stdio.h>

int main() {
    int vet[50], n, menor, aux;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("vet[%d] = ", i);
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        menor = i;
        for (int j = i + 1; j < n; j++) {
            if (vet[j] < vet[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            aux = vet[i];
            vet[i] = vet[menor];
            vet[menor] = aux;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
}