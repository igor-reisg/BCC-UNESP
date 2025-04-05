#include<stdio.h>

int main () {

    float precoet, precofim;
    int pag;

    printf("Digite o preco de etiqueta e a forma de pagamento (1 a 5): ");
    printf("\n1 - A vista em dinheiro ou cheque, recebe 10 %% de desconto");
    printf("\n2 - A vista no cartao de credito, recebe 5%% de desconto");
    printf("\n3 - Em 2 vezes, preco normal da etiqueta sem juros");
    printf("\n4 - Em 3 vezes, preco normal de etiqueta mais juros de 10%%\n");
    scanf("%f %d", &precoet, &pag);

    if (pag == 1) {
        precofim = precoet*0.90;
    }
    else if (pag == 2) {
        precofim = precoet*0.95;
    }
    else if (pag == 3) {
        precofim = precoet;
    }
    else if (pag == 4) {
        precofim = precoet*1.10;
    }
    else
        printf("Codigo invalido\n");

    printf("O preco a ser pago pelo produto eh R$%.2f", precofim);
}
