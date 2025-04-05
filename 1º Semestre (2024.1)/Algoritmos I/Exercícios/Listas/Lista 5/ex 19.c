#include <stdio.h>

int main () {

    int n, i;

    printf("Digite um numero: ");
    scanf("%d", &n);

    if (n > 0) {
        for (i = 1; i <= n; i++) {
            printf("%d^2 = %d\n", i, i*i);
        }
    }
    else {
        for (i = n; i <= 1; i++) {
            printf("%d^2 = %d\n", i, i*i);
        }
    }
}