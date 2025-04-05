#include <stdio.h>

int main () {

    int sex, corolho, corcabelo, idade, idademaior = 0, continuar = 1, hab = 0;
    int pessoaesp = 0;
    float porcpessoaesp;

    while (continuar == 1) {

        printf("Sexo (1-Masculino | 2-Feminino): ");
        scanf("%d", &sex);

        printf("\nCor dos olhos (1-Azuis | 2-Verdes | 3-Castanhos): ");
        scanf("%d", &corolho);

        printf("\nCor dos cabelos (1-Louros | 2-Castanhos | 3-Pretos): ");
        scanf("%d", &corcabelo);

        printf("\nIdade: ");
        scanf("%d", &idade);

        hab++;

        if (idade > idademaior) {
            idademaior = idade;
        }

        if (sex == 2) {
            if (idade >= 18 && idade <= 35) {
                if (corolho == 2) {
                    if (corcabelo == 1) {
                        pessoaesp++;
                    }
                }
            }
        }

        printf("Executar novamente? (1-sim | 2-nao)\n");
        scanf("%d", &continuar);
    }

    porcpessoaesp = (float)pessoaesp / hab * 100;

    printf("Habitante com maior idade: %d\n", idademaior);
    printf("Porcentagem de pessoas do sexo feminino de eidade entre 18 e 35 anos que possui olhos verdes e cabelos louros: %.2f", porcpessoaesp);
}