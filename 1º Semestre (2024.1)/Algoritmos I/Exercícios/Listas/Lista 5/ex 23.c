#include <stdio.h>

int main () {

    int i, n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    for (i = 0; i <= 10; i++) {
        printf("%d * %d = %d\n", n, i, n*i);
    }
}