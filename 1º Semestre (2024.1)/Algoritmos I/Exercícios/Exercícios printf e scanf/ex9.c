#include <stdio.h>

int main () {

    float cel, fahren;

    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &cel);

    fahren = 9*cel/5 + 32;

    printf("%.2f graus Celsius em Fahrenheit eh %.2f", cel, fahren);


}