#include <stdio.h>
#include <stdlib.h>

int main() {
    char hex[17];
    int dec;

    printf("Digite um numero hexadecimal: ");
    gets(hex);

    dec = strtol(hex, NULL, 16);

    printf("O numero decimal equivalente eh: %d\n", dec);
}