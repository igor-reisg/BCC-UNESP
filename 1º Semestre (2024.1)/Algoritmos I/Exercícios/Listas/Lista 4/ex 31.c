#include <stdio.h>

int main () {

    int i, cod, maiorcidade, menorcidade, veiculo, acidentes, maioracidente = 0, menoracidente = 0;
    int somaveiculo = 0, somaacidente = 0, qtdpoucoveiculo = 0;
    float medveiculo, medacidente;

    for (i = 0; i < 5; i++) {
        printf("Cidade %d:\n", i+1);
        printf("Codigo da cidade: ");
        scanf("%d", &cod);

        printf("Numero de veiculos de passeio: ");
        scanf("%d", &veiculo);

        printf("Numero de acidentes de transito com vitimas: ");
        scanf("%d", &acidentes);

        if (acidentes > maioracidente) {
            maioracidente = acidentes;
            maiorcidade = i+1;
        }
        
        if (acidentes < menoracidente || i == 0) {
            menoracidente = acidentes;
            menorcidade = i+1;
        }

        somaveiculo += veiculo;

        if (veiculo < 2000) {
            somaacidente += acidentes;
            qtdpoucoveiculo++;
        }
    }

    medveiculo = (float)somaveiculo/5;

    medacidente = (float)somaacidente/qtdpoucoveiculo;

    printf("\nMaior indice de acidentes de transito: %d\nPertence a cidade %d\n", maioracidente, maiorcidade);
    printf("Menor indice de acidentes de transito: %d\nPertence a cidade %d\n", menoracidente, menorcidade);
    printf("Media de veiculos entre as 5 cidades: %.2f\n", medveiculo);
    printf("Media de acidentes de transito nas cidades com menos de 2000 veiculos: %.2f\n", medacidente);
}
