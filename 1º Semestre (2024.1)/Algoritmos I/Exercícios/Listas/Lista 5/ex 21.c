#include <stdio.h>

int main () {

    int i, a, b, soma = 0;

    printf("Digite 2 numeros: ");
    scanf("%d %d", &a, &b);

    if (a > b) {
        for (i = b + 1; i <= a - 1; i++) {
            soma += i;
        }
    }
    else if (b > a) {
        for (i = a + 1; i <= b - 1; i++) {
            soma += i;
        }
    }
    else   
        soma = 0;

    printf("soma de todos os inteiros entre A e B: %d\n", soma);
}