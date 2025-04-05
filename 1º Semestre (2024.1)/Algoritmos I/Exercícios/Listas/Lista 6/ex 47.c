#include <stdio.h>

int main() {
    int dia1, mes1, ano1, dia2, mes2, ano2;
    int dias = 0, ano, mes;

        printf("Digite a primeira data (dia mes ano): ");
        scanf("%d %d %d", &dia1, &mes1, &ano1);

        printf("Digite a segunda data (dia mes ano): ");
        scanf("%d %d %d", &dia2, &mes2, &ano2);


    while (ano2 < ano1 || (ano2 == ano1 && mes2 < mes1) || (ano2 == ano1 && mes2 == mes1 && dia2 < dia1)) {
        
        printf("Erro, digite novamente:\n");

        printf("Digite a primeira data (dia mes ano): ");
        scanf("%d %d %d", &dia1, &mes1, &ano1);

        printf("Digite a segunda data (dia mes ano): ");
        scanf("%d %d %d", &dia2, &mes2, &ano2);

    }

    for (ano = ano1; ano < ano2; ano++) {
        dias += 365;
    }

    for (mes = 1; mes < mes1; mes++) {
        if (mes == 2)
            dias -= 29;
        else if (mes == 2)
            dias -= 28;
        else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
            dias -= 30;
        else
            dias -= 31;
    }
    dias -= dia1;

    for (mes = 1; mes < mes2; mes++) {
        if (mes == 2)
            dias += 29;
        else if (mes == 2)
            dias += 28;
        else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
            dias += 30;
        else
            dias += 31;
    }
    dias += dia2;

    printf("Numero de dias entre as duas datas: %d\n", dias);
}
