#include<stdio.h>

int main () {

    float sal, novosal;

    printf("Digite o seu salario: R$");
    scanf("%f", &sal);

    if (sal < 840.0) {
        novosal = sal*1.13;
        printf("Valor do salario reajustado: R$%.2f", novosal);
    }
    else    
        printf("Voce nao tem direito ao aumento de salario");
}
