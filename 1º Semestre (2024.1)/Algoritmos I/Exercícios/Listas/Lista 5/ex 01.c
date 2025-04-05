#include <stdio.h>

int main () {

    int n, j, i, fat, num;

    printf("Numeros a serem lidos: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        fat = 1;

        printf("Digite um valor inteiro e positivo: ");
        scanf("%d", &num);

        for (j = num; j >= 1; j--) {
            fat *= j;
        }
        printf("%d! = %d\n", num, fat);
    }
}