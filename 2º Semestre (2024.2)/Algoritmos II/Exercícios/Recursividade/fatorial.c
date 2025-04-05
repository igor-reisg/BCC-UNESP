#include <stdio.h>

float fatorial_iterativo(int x) {
    float fat = 1;

    for(int i = 1; i <= x; i++) {
        fat *= i;
    }
    return fat;
}

float fatorial_recursivo(int x) {
    if (x == 1) {
        return x;
    }
    return x * fatorial_recursivo(x - 1);
}

int main() {
    int n;

    printf("Digite o numero que deseja saber o seu fatorial: ");
    scanf("%d", &n);

    printf("(Iterativo) %d! = %.0f\n", n, fatorial_iterativo(n));
    printf("(Recursivo) %d! = %.0f\n", n, fatorial_recursivo(n));
}