#include <stdio.h>

int main() {
    
    int N, i, vet[1000], maxtam = 1, tamatual = 1;

    printf("Digite o numero de elementos na sequencia: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("O comprimento do segmento crescente maximo é 0\n");
    }

    printf("Digite os %d números inteiros:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &vet[i]);
    }

    for (i = 1; i < N; i++) {
        if (vet[i] > vet[i - 1]) {
            tamatual++;
        } else {
            if (tamatual > maxtam) {
                maxtam = tamatual;
            }
            tamatual = 1;
        }
    }

    if (tamatual > maxtam) {
        maxtam = tamatual;
    }
    printf("O comprimento do segmento crescente máximo é %d\n", maxtam);
}
