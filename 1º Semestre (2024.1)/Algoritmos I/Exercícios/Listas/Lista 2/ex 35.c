#include<stdio.h>

int main () {
   
    float kwatts, salmin, valkwatts, valtot, valnew;
    
    printf("Digite o valor do salário mínimo: R$");
    scanf("%f", &salmin);
    
    printf("Digite a quatidade de quilowatts gasta pela residência: ");
    scanf("%f", &kwatts);
    
    valkwatts = (float)1/5*salmin;
    
    valtot = kwatts*valkwatts;
    
    valnew = valtot - (valtot*15/100);
    
    printf("O valor de cada quilowatts é %.2f\n", valkwatts);
    printf("O valor a ser pago pela residência é %.2f\n", valtot);
    printf("O novo valor a ser pago com o desconto é %.2f\n", valnew);
}
