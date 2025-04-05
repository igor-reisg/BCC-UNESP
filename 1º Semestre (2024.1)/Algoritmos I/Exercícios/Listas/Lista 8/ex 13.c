#include <stdio.h>

int main () {

    int quant, i;
    float notas[40], percabaixo = 0, percacima = 0, maior, menor, razao, med, soma = 0;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &quant);

    for (i = 0; i < quant; i++) {
        printf("Nota aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    maior = notas[0];
    menor = notas[0];

    for (i = 0; i < quant; i++) {
        soma += notas[i];

        if (maior < notas[i]) {
            maior = notas[i];
        }

        if (menor > notas[i]) {
            menor = notas[i];
        }

        if (notas[i] < 5.0) {
            percabaixo++;
        }
        else
            percacima++;
    }

    med = soma / quant;
    razao = maior / menor;
    percabaixo = percabaixo / quant * 100;
    percacima = percacima / quant * 100;

    printf("Media aritmetica = %.2f\nPercentual de valores abaixo da media = %.2f%%\n", med, percabaixo);
    printf("Percentual de valores acima da media = %.2f%%\nRazao entre o maior e o menor valor = %.2f", percacima, razao);
}