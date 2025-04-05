#include <stdio.h>

int main() {
    int vet[50], n, aux, j;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("vet[%d] = ", i);
        scanf("%d", &vet[i]);
    }

    for (int i = 1; i < n; i++) {
        aux = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] > aux) {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
}