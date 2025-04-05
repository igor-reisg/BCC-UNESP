#include<stdio.h>

int main () {
   
   float valor, taxa, rend, total;
   
   printf("Valor do depósito: ");
   scanf("%f", &valor);
   
   printf("Valor da taxa de juros: ");
   scanf("%f", &taxa);
   
   rend = valor*taxa/100;
   
   total = rend + valor;
   
   printf("Valor do rendimento: R$%.2f\n", rend);
   printf("Valor total c/ o rendimento: R$%.2f\n", total);
   
}
