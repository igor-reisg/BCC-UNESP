#include <stdio.h>

int main() {
    int dia, mes;

    printf("Digite o dia do seu nascimento: ");
    scanf("%d", &dia);
    printf("Digite o mes do seu nascimento: ");
    scanf("%d", &mes);

    if ((mes == 1 && dia <= 20) || (mes == 12 && dia >= 22)) {
        printf("Capricornio\n");
    } else if ((mes == 1 && dia >= 21) || (mes == 2 && dia <= 19)) {
        printf("Aquario\n");
    } else if ((mes == 2 && dia >= 20) || (mes == 3 && dia <= 20)) {
        printf("Peixes\n");
    } else if ((mes == 3 && dia >= 21) || (mes == 4 && dia <= 20)) {
        printf("Aries\n");
    } else if ((mes == 4 && dia >= 21) || (mes == 5 && dia <= 20)) {
        printf("Touro\n");
    } else if ((mes == 5 && dia >= 21) || (mes == 6 && dia <= 20)) {
        printf("Gameos\n");
    } else if ((mes == 6 && dia >= 21) || (mes == 7 && dia <= 21)) {
        printf("Cancer\n");
    } else if ((mes == 7 && dia >= 22) || (mes == 8 && dia <= 22)) {
        printf("Leao\n");
    } else if ((mes == 8 && dia >= 23) || (mes == 9 && dia <= 22)) {
        printf("Virgem\n");
    } else if ((mes == 9 && dia >= 23) || (mes == 10 && dia <= 22)) {
        printf("Libra\n");
    } else if ((mes == 10 && dia >= 23) || (mes == 11 && dia <= 21)) {
        printf("Escorpiao\n");
    } else if ((mes == 11 && dia >= 22) || (mes == 12 && dia <= 21)) {
        printf("Sagitario\n");
    } else {
        printf("Data de nascimento invalida\n");
    }
}
