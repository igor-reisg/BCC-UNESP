#include <stdio.h>

int main () {

    int x, y, i, pot = 1;

    printf("Digite dois valores inteiros e postivos: ");
    scanf("%d %d", &x, &y);

    while (x < 0 || y < 0) {
        printf("Valores invalidos. Digite novamente: ");
        scanf("%d %d", &x, &y);
    }

    for (i = 1; i <= y; i++) {
        pot *= x;
    }

    printf("%d^%d = %d", x, y, pot);
}