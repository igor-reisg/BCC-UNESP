#include <stdio.h>

int main () {

    int quantdia, quantanos;
    float preco, total;

    printf("Digite a quantidade de cigarros fumados por dia: ");
    scanf("%d", &quantdia);

    printf("Digite a quantidade de anos que fuma: ");
    scanf("%d", &quantanos);

    printf("Digite o preco medio da carteira de cigarros: ");
    scanf("%f", &preco);

    total = quantdia*365*quantanos*preco/20;

    printf("A quantidade de dinheiro gasto pelo fumante durante %d anos eh de %.2f", quantanos, total);

}