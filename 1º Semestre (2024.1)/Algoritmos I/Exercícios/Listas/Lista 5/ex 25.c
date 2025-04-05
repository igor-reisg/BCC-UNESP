#include <stdio.h>

int main () {

    int n, cont, soma = 0;
    float med;

    printf("Digite um valor inteiro positivo: ");
    scanf("%d", &n);

    while (n > 0) {

        if (n > 0) {

            soma += n;
            cont++;
        }

        printf("Digite um valor inteiro positivo: ");
        scanf("%d", &n);
    }

    med = (float)soma/cont;

    printf("media = %.2f", med);
}