#include <stdio.h>

int main () {

    int i, j, ti, tj;

    printf("Digite a linha em que a Torre se encontra: ");
    scanf("%d", &ti);

    printf("Digite a coluna em que a Torre se encontra: ");
    scanf("%d", &tj);
    
    //primeira linha
    printf("  | ");
    for (i = 1; i <= 8; i++) {
        printf("%d  ", i);
    }
    printf("\n");

    //segunda linha
    for (i = 1; i <= 28; i++) {
        printf("-");
    }
    printf("\n");

    //tabuleiro
    for (i = 1; i <= 8; i++) {
        //primeira coluna
        printf("%d |", i);

        for (j = 1; j <= 8; j++) {
            if (ti == i || tj == j) {
                printf(" x ");
            }
            else
                printf(" - ");
        }
        printf("\n");
    }
}