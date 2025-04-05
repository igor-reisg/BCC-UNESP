#include <stdio.h>

int somavetor_iterativo(int x, int vet[]) {
    int soma = 0;

    for (int i = 0; i < x; i++) {
        soma += vet[i];
    }
    return soma;
}

int somavetor_recursivo(int x, int vet[]) {
    if (x == 0) {
        return 0;
    }
    return vet[x - 1] + somavetor_recursivo(x - 1, vet);
}

int main() {
    int n, vet[20];

    printf("Quantidade de elementos do vetor (max: 20): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("vet[%d] = ", i);
        scanf("%d", &vet[i]);
    }

    printf("(Iterativo) A soma dos elementos do vetor eh: %d\n", somavetor_iterativo(n, vet));
    printf("(Recursivo) A soma dos elementos do vetor eh: %d\n", somavetor_recursivo(n, vet));
}