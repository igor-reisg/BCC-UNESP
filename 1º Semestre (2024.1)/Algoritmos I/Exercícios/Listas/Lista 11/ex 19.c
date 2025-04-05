#include <stdio.h>
#include <string.h>

int transformaMesNumero(char* mes) {
    if (strcmp(mes, "Janeiro") == 0) return 1;
    if (strcmp(mes, "Fevereiro") == 0) return 2;
    if (strcmp(mes, "Março") == 0) return 3;
    if (strcmp(mes, "Abril") == 0) return 4;
    if (strcmp(mes, "Maio") == 0) return 5;
    if (strcmp(mes, "Junho") == 0) return 6;
    if (strcmp(mes, "Julho") == 0) return 7;
    if (strcmp(mes, "Agosto") == 0) return 8;
    if (strcmp(mes, "Setembro") == 0) return 9;
    if (strcmp(mes, "Outubro") == 0) return 10;
    if (strcmp(mes, "Novembro") == 0) return 11;
    if (strcmp(mes, "Dezembro") == 0) return 12;
    return -1;
}

int main() {
    
    int dia, ano, mesNum;
    char mes[20];

    printf("Digite a data no formato (dia, mes(maiusculo) ano): ");
    scanf("%d, %s %d", &dia, mes, &ano);

    mesNum = transformaMesNumero(mes);
    
    if (mesNum == -1) { 
        printf("Mes invalido!\n");
    } 
    else {
        printf("%d/%d/%d\n", dia, mesNum, ano);
    }
    return 0;
}
