#include <stdio.h>

int main () {

    float salmin, sal, salliq, saltot, salbruto, valhrtrab, valhrextra;
    int hrtrab, ndep, hrextra;

    printf("Digite o valor do salario minimo, numero de horas trabalhadas, numero de dependentes e numero de horas extras trabalhadas: ");
    scanf("%f %d %d %d", &salmin, &hrtrab, &ndep, &hrextra);

    valhrtrab = (float)1/5*salmin*hrtrab;

    sal = valhrtrab+(ndep*32);

    valhrextra = (float)1/5*salmin*hrextra*1.5;

    salbruto = sal+valhrextra;

    if (salbruto < 900.0) {
        salliq = salbruto;
    }
    else if (salbruto >= 900.0 && salbruto <= 1400.0) {
        salliq = salbruto - (salbruto*0.10);
    }
    else   
        salliq = salbruto - (salbruto*0.20);

    if (salliq <= 950.0) {
        saltot = salliq + 100.0;
    }
    else
        saltot = salliq + 50.0;

    printf("Salario a receber: R$%.2f", saltot);
}