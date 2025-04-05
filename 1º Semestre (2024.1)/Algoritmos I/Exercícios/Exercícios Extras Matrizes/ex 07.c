#include <stdio.h>
#define max 15

int main() {
    
    int i, j, n, mat[max][max], lin, col, num = 1;

    printf("Digite a ordem da matriz: ");
    scanf("%d", &n);

    lin = 0;
    col = n / 2;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mat[i][j] = 0;
        }
    }

    while (num <= n * n) {
        mat[lin][col] = num;
        num++;
        lin--;
        col++;

        if (lin < 0 && col == n) {
            lin = 1;
            col = n - 1;
        } 
        else {
            if (lin < 0) {
                lin = n - 1;
            }
            if (col == n) {
                col = 0;
            }
        }

        if (mat[lin][col] != 0) {
            lin += 2;
            col--;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
}
