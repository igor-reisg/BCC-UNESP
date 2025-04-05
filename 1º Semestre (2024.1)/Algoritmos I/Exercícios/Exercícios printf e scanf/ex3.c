#include<stdio.h>

int main () {

    float peso, alt, imc;

    printf("Digite o peso (em kg): ");
    scanf("%f", &peso);

    printf("Digite a altura (em m): ");
    scanf("%f", &alt);
    
    imc = peso / (alt*alt);

    printf("O seu IMC eh: %.2f", imc);
}