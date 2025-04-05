#include <stdio.h>

float potencia_iterativo(int x, int y) {
    float res = 1;

    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

float potencia_recursivo(int x, int y) {
    if (y == 1) {
        return x;
    }
    return x * potencia_recursivo(x, y - 1);
}

int main() {
    int x, y;

    printf("Digite o numero e a sua potencia: ");
    scanf("%d %d", &x, &y);

    printf("(Iterativo) %d elevado a %d: %.0f\n", x, y, potencia_iterativo(x, y));
    printf("(Recursivo) %d elevado a %d: %.0f\n", x, y, potencia_recursivo(x, y));
}