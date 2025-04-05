#include <stdio.h>

int main () {

    int num;
    char carac;

    printf("Digite um numero: ");
    scanf("%d", &num);

    carac = num;

    printf("%d = %c", num, carac);
}