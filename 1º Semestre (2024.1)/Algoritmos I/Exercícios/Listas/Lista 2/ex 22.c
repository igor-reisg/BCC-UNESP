#include<stdio.h>
#include<math.h>

int main () {
    
    float x, frac, arred;
    int inteira;
    
    printf("Escreva um número real: ");
    scanf("%f", &x);
    
    inteira = x;
    
    frac = x - (float)inteira;
    
    arred = ceil(x);
    
    printf("Parte inteira de %.2f: %d\n", x, inteira);
    printf("Parte fracionária de %.2f: %.2f\n", x, frac);
    printf("Número %.2f arredondado: %.2f\n", x, arred);
    
}
