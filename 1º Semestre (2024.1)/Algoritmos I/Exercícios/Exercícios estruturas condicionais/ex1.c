#include<stdio.h>

int main () {

    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    //Verificação se o num é par
    if (num % 2 == 0) {
        printf("O numero %d e par\n", num);
    }
    //Se num é ímpar
    else
        printf("O numero %d e impar\n", num);
}

