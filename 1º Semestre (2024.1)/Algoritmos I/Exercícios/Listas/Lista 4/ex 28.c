#include <stdio.h>

int main () {

    int idade, gruporisco, codseg;

    printf("Digite sua idade e o seu grupo de risco (1 - Baixo, 2 - Medio, 3 - Alto): ");
    scanf("%d %d", &idade, &gruporisco);

    if (idade >= 18 && idade <= 24) {
        switch (gruporisco) {
            case 1:
                codseg = 7;
                break;
            case 2:
                codseg = 8;
                break;
            case 3:
                codseg = 9;
                break;
            default:
                printf("Grupo de risco invalido\n");
        }
        printf("Codigo do seguro: %d", codseg);
    }
    else if (idade >= 25 && idade <= 40) {
        switch (gruporisco) {
            case 1:
                codseg = 4;
                break;
            case 2:
                codseg = 5;
                break;
            case 3:
                codseg = 6;
                break;
            default:
                printf("Grupo de risco invalido\n");
        }
        printf("Codigo do seguro: %d", codseg);
    }
    else if (idade >= 40 && idade <= 70) {
        switch (gruporisco) {
            case 1:
                codseg = 1;
                break;
            case 2:
                codseg = 2;
                break;
            case 3:
                codseg = 3;
                break;
            default:
                printf("Grupo de risco invalido\n");
        }
        printf("Codigo do seguro: %d", codseg);
    }
    else 
        printf("Idade invalida\n"); 
}