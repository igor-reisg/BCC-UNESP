#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int funcaoHash(int elemento, char val, char pos) {
    return (val - 65) + elemento + pos;
}

int main() {
    int t, l;
    char frase[51];

    scanf("%d", &t);

    while (t--) {
        int soma = 0;

        scanf("%d", &l);

        for (int i = 0; i < l; i++) {
            scanf("%s", frase);

            for (unsigned int j = 0; j < strlen(frase); j++) {
                soma += funcaoHash(i, frase[j], j);
            }
        }
        printf("%d\n", soma);
    }
}