#include<stdio.h>
#include<math.h>

int main () {
   
    float graus, rad;
    
    printf("Digite um ângulo (em graus): ");
    scanf("%f", &graus);
    
    rad = graus*M_PI/180;

    printf("O seno de %.2f graus é %.2f\n", graus, sin(rad));
    printf("O cosseno de %.2f graus é %.2f\n", graus, cos(rad));
    printf("A tangente de %.2f graus é %.2f\n", graus, tan(rad));
}
