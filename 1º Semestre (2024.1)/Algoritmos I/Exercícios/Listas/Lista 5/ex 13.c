#include <stdio.h>

int main () {

    int n, i, j;

    printf("Digite um vaor inteiro nao negativo: ");
    scanf("%d", &n);

    while (n < 0) {
        printf("Valor invalido. Digite novamente: ");
        scanf("%d", &n);
    }

    for (i = n; i >= 1; i--) {

        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}