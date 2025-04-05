#include<stdio.h>

int main () {
    
    float hr, velmed, dist, consumo;
    
    printf("Digite o tempo, velocidade média e distância: ");
    scanf("%f %f %f", &hr, &velmed, &dist);
    
    consumo = (hr*dist)/velmed;
    
    printf("O consumo é de %.2f", consumo);
}
