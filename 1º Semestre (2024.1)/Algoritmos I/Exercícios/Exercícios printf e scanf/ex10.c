#include <stdio.h>

int main () {

    float preco, precototal, imp, lucro;

    printf("Preco de custo do produto: ");
    scanf("%f", &preco);

    imp = 0.45*preco;
    lucro = 0.5*preco;

    precototal = preco+imp+lucro;

    printf("O preco final do produto eh %.2f reais", precototal);

}