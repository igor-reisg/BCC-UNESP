#include <stdio.h>

int main() {
    int ano, mil, cem, dezena, centena;

    printf("Digite um ano entre 1000 e 3000: ");
    scanf("%d", &ano);

    while (ano < 1000 || ano > 3000) {
        printf("Digite um ano entre 1000 e 3000: ");
        scanf("%d", &ano);
    }

    mil = ano / 1000;
    cem = (ano % 1000) / 100;
    dezena = (ano % 100) / 10;
    centena = ano % 10;

    printf("O ano em numeros romanos: ");
    
    switch (mil) {
        case 1:
            printf("M");
            break;
        case 2:
            printf("MM");
            break;
        case 3:
            printf("MMM");
            break;
    }
    
    switch (cem) {
        case 1:
            printf("C");
            break;
        case 2:
            printf("CC");
            break;
        case 3:
            printf("CCC");
            break;
        case 4:
            printf("CD");
            break;
        case 5:
            printf("D");
            break;
        case 6:
            printf("DC");
            break;
        case 7:
            printf("DCC");
            break;
        case 8:
            printf("DCCC");
            break;
        case 9:
            printf("CM");
            break;
    }

    switch (dezena) {
        case 1:
            printf("X");
            break;
        case 2:
            printf("XX");
            break;
        case 3:
            printf("XXX");
            break;
        case 4:
            printf("XL");
            break;
        case 5:
            printf("L");
            break;
        case 6:
            printf("LX");
            break;
        case 7:
            printf("LXX");
            break;
        case 8:
            printf("LXXX");
            break;
        case 9:
            printf("XC");
            break;
    }
    
    switch (centena) {
        case 1:
            printf("I");
            break;
        case 2:
            printf("II");
            break;
        case 3:
            printf("III");
            break;
        case 4:
            printf("IV");
            break;
        case 5:
            printf("V");
            break;
        case 6:
            printf("VI");
            break;
        case 7:
            printf("VII");
            break;
        case 8:
            printf("VIII");
            break;
        case 9:
            printf("IX");
            break;
    }
    printf("\n");
}
