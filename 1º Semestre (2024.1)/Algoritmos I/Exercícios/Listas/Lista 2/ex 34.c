#include<stdio.h>

int main () {
   
    float sal, aumento, total;
    
    printf("Coloque seu salário: R$");
    scanf("%f", &sal);
    
    aumento = sal*22/100;
    
    total = aumento + sal;
    
    printf("O seu novo salário é R$%.2f", total);
}
