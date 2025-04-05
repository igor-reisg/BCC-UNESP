#include <stdio.h>

int main() {
    
    int vetor[100], n, i, j, k, tamatual;

    printf("Digite o numero de elementos no vetor (maximo de 100): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    tamatual = n;

    for (i = 0; i < tamatual; i++) {
        for (j = i + 1; j < tamatual; j++) {
            if (vetor[i] == vetor[j]) {
                for (k = j; k < tamatual - 1; k++) {
                    vetor[k] = vetor[k + 1];
                }
                tamatual--; 
                j--; 
            }
        }
    }

    printf("Vetor resultante:\n");
    for (i = 0; i < tamatual; i++) {
        printf("%d ", vetor[i]);
    }
}
