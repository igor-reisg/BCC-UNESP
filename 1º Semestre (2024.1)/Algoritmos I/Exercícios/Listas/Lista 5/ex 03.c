#include <stdio.h>

int main () {

    int x, y, i, soma = 0, mult = 1;

    printf("Digite 2 numeros: ");
    scanf("%d %d", &x, &y);

    if (x >= y) {
        for (i = y; i <= x; i++) {
            if (i % 2 != 0) {
                soma += i;
            }
            else
                mult *= i;
        }
    }
    else
        for (i = x; i <= y; i++) {
            if (i % 2 != 0) {
                soma += i;
            }
            else
                mult *= i;
        }

    printf("Soma dos numeros impares do intervalo: %d\n", soma);
    printf("Multiplicacao dos numeros pares do intervalo: %d\n", mult);
}