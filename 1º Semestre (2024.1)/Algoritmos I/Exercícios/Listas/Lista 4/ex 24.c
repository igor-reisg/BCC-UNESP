#include<stdio.h>

int main () {

    float sal, novosal;

    printf("Digite o seu salario: R$");
    scanf("%f", &sal);

    if (sal <= 1350.0) {
        novosal = sal*1.255;
    }
    else
        novosal = sal*1.1225;

    printf("Valor do salario reajustado: R$%.2f", novosal);
}
