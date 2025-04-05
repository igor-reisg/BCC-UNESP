#include<stdio.h>
#include<math.h>

int main () {
    
    float vol, r;    
    
    printf("Digite o valor do raio da esfera: ");
    scanf("%f", &r);
    
    vol = (float)4/3*M_PI*pow(r, 3);
    
    printf("O volume da esfera de raio %.2f é %.2f", r, vol);
}
