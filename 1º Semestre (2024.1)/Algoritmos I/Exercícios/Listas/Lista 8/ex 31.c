#include <stdio.h>
#include <string.h>

int main() {

    int seq1[100], seq2[100], result[101], N, i, carrega = 0, soma;

    printf("Digite o valor de N: ");
    scanf("%d", &N);

    printf("Digite a 1 sequencia de %d numeros: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &seq1[i]);
    }

    printf("Digite a 2 sequencia de %d numeros: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &seq2[i]);
    }

    for (i = N - 1; i >= 0; i--) {
        soma = seq1[i] + seq2[i] + carrega;
        result[i + 1] = soma % 10;
        carrega = soma / 10;
    }

    result[0] = carrega;

    printf("Resultado: ");
    for (i = 0; i < N + 1; i++) {
        if (i == 0 && result[i] == 0) {
            continue;
        }
        printf("%d", result[i]);
    }
    printf("\n");
}
