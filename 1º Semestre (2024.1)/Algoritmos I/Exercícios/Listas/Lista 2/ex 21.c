#include<stdio.h>

int main () {
   
    float nt1, nt2, peso1, peso2, med;
    
    printf("Nota 1 e seu peso: ");
    scanf("%f %f", &nt1, &peso1);
    
    printf("Nota 2 e seu peso: ");
    scanf("%f %f", &nt2, &peso2);
    
    med = (nt1*peso1+nt2*peso2)/(peso1+peso2);
    
    printf("Sua média é %.2f", med);
}
