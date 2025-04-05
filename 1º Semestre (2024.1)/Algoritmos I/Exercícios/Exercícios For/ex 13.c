#include <stdio.h>

int main () {

    int i, j;

    //primeira linha
    printf("       ");
    for (i = 1; i <= 20; i++) {
        if (i % 2 != 0) {
            printf("%3d ", i);
        }
    }
    printf("\n");

    //segunda linha
    for (i = 1; i <= 55; i++) {
        printf("-");
    }
    printf("\n");

    //tabuada
    for (i = 1; i <= 20; i++) {
        //primeira coluna
        if (i % 2 != 0) {
            printf("%4d |", i);

            for (j = 1; j <= 20; j++) {
                if (j % 2 != 0) {
                    printf("%4d", i*j);
                }
            }
        }
        printf("\n");
    }
}