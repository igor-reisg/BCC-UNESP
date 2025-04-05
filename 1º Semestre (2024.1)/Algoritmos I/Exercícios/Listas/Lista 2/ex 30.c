#include<stdio.h>

int main () {
   
    float sal, salmin, quantsalmin;
    
    printf("Digite o seu salário: R$");
    scanf("%f", &sal);
    
    printf("Digite o valor do salário mínimo: R$");
    scanf("%f", &salmin);
    
    quantsalmin = sal/salmin;
    
    printf("Você ganha %.2f salários mínimos", quantsalmin);
}
