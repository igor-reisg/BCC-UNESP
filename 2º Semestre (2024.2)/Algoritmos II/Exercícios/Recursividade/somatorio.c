#include <stdio.h>

float somatorio_iterativo(int x) {
    float soma = 0;

    for (int i = 1; i <= x; i++) {
        soma += i;
    }
    return soma;
}

float somatorio_recursivo(int x) {
    if (x == 1) {
        return 1;
    }
    return x + somatorio_recursivo(x - 1);
}

int main() {
    int n;

    printf("Digite ate que numero deseja saber o somatorio: ");
    scanf("%d", &n);

    printf("(Iterativo) Somatorio de 1 ate %d: %.0f\n", n, somatorio_iterativo(n));
    printf("(Recursivo) Somatorio de 1 ate %d: %.0f\n", n, somatorio_recursivo(n));
}