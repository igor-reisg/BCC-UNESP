#include <stdio.h>

int main () {

    int x, y, prod = 0;

    printf("Digite 2 valores: ");
    scanf("%d %d", &x, &y);

    while (x > 0) {

        if (x % 2 != 0) {
            prod += y;
        }

        x /= 2;
        y *= 2;
    }
    printf("O produto eh: %d\n", prod);
}