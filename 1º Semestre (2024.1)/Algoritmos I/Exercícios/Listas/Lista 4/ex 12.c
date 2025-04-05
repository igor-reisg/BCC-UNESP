#include<stdio.h>

int main () {

    float alt, pesoideal;
    double peso;
    int sexo;

    printf("Digite sua altura e peso: ");
    scanf("%f %lf", &alt, &peso);

    printf("Digite seu sexo:\n1 - Masculino\n2 - Feminino\n");
    scanf(" %d", &sexo);

    if (sexo == 1) {
        pesoideal = 72.7*alt-58.0;
    }
    else if (sexo == 2) {
        pesoideal = 62.1*alt-44.7;
    }
    else
        printf("Sexo nao identificado\n");

    printf("Peso ideal: %f kg\nSeu peso: %lf kg\n", pesoideal, peso);

    if (peso < pesoideal) {
        printf("Voce esta abaixo do seu peso ideal\n");
    }
    else if (peso > pesoideal) {
        printf("Voce esta acima do seu peso ideal\n");
    }
    else  
        printf("Voce esta no seu peso ideal\n");
}
