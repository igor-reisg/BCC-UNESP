#include<stdio.h>

int main () {

    float vel;

    printf("Digite uma velocidade em m/s: ");
    scanf("%f", &vel);

    printf("A velocidade %.2f m/s em Km/h eh %.2f km/h", vel, vel*3.6);

}