#include <stdio.h>

int main () {

    int x, y, i, j;

    printf("Digite os valores de x e y: ");
    scanf("%d %d", &x, &y);

    //primeira linha
    printf("     | ");
    for (i = x; i <= y; i++) {
        printf("%3d ", i);
    }
    printf("\n");

    //segunda linha
    for (i = 1; i <= 55; i++) {
        printf("-");
    }
    printf("\n");

    //tabuada
    for (i = x; i <= y; i++) {
        //primeira coluna
        printf("%4d |", i);
    
        for (j = x; j <= y; j++) {
            printf("%4d", i*j);
        }
        printf("\n");
    }
}