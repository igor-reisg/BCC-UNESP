#include <stdio.h>

int main () {

    int N, tot, cinq, dez, cinco, um, teste = 0;

    scanf("%d", &N);

    while (N != 0) {

        teste++;
        tot = N;

        cinq = tot / 50;
        tot %= 50;

        dez = tot / 10;
        tot %= 10;

        cinco = tot / 5;
        tot %= 5;

        um = tot;

        printf("Teste %d\n%d %d %d %d\n\n", teste, cinq, dez, cinco, um);

        scanf("%d", &N);
    }
}