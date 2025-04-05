#include<stdio.h>

int main () {

    int idade;

    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    if (idade >= 0 && idade <= 2) {
        printf("Recem-nascido\n");
    }
    else if (idade >= 3 && idade <= 11) {
        printf("Crianca\n");
    }
    else if (idade >= 12 && idade <= 19) {
        printf("Adolescente\n");
    }
    else if (idade >= 20 && idade <= 55) {
        printf("Adulto\n");
    }
    else if (idade >= 55) {
        printf("Idoso\n");
    }
    else
        printf("Idade invalida\n");
}
