#include <stdio.h>

int main () {

    float soma = 0;
    int i, j, n;

    printf("Digite um valor: ");
    scanf("%d", &n);

    for (i = 1, j = n; i <= n; i++) {

        soma += (float)i/j;
        j--;
    }

    printf("soma = %.2f\n", soma);
}