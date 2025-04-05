#include <stdio.h>

int main() {

    float a, b, soma, med;

    printf("Digita 2 numeros reais: ");
    scanf("%f %f", &a, &b);
    
    soma = a + b;
    med = soma/2;

    printf("A media de %.2f e %.2f eh %.2f", a, b, med);

}