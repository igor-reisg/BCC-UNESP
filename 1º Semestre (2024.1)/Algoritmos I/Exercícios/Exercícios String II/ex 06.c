#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
   
    char s[50];
    int num;
   
    printf("Digite um numero: ");
    scanf("%d", &num);
   
    itoa(num, s, 16);
   
    printf("Valor de %d em hexadecimal: %s", num, s);
}
