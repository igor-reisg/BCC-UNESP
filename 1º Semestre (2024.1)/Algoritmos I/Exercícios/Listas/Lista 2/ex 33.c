#include<stdio.h>

int main () {
   
    float sal, imp;
    
    printf("Coloque seu salário: R$");
    scanf("%f", &sal);
    
    imp = (float)5/100*sal;
    
    printf("O valor do imposto de renda a ser pago é R$%.2f", imp);
    
}
