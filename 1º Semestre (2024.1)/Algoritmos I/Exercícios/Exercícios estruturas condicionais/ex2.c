#include<stdio.h>

int main () {

    int a, b, c, sum;

    printf("Insira 3 numeros: ");
    scanf("%d %d %d", &a, &b, &c);

    //A é o menor
    if (a<b && a<c) {
        sum = b+c;
    }
    //B é o menor
    else if (b<a && b<c) {
        sum = a+c;
    }
    //C é o menor
    else
        sum = a+b;

    printf("SOMA = %d", sum);
}