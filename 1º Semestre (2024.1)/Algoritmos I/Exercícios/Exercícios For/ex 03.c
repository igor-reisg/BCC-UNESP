#include <stdio.h>

int main () {

    int i, inf, sup, soma = 0;

    scanf("%d %d", &inf, &sup);

    for (i = inf+1; i < sup; i++) {

        if (i % 2 == 0) {
            printf("%d\n", i);

            soma += i;
        }
    }
    printf("SOMA: %d", soma);
}