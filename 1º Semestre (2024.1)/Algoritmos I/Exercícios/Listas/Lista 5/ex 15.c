#include <stdio.h>

int main () {

    int anonasc, anoat, idade, idadesemana;

    printf("Digite o seu ano de nascimento e o ano atual: ");
    scanf("%d %d", &anonasc, &anoat);

    idade = anoat - anonasc;

    idadesemana = idade * 52;

    printf("idade: %d\nidade em semanas: %d\n", idade, idadesemana);
}