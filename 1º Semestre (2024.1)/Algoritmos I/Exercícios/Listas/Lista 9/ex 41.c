#include <stdio.h>

#define MAX 100

int matPerm(int mat[][MAX], int n) {
    int i, j;
    
    for (i = 0; i < n; i++) {
        int somalin = 0, somacol = 0;
        for (j = 0; j < n; j++) {
            somalin += mat[i][j];
            somacol += mat[j][i];
        }
        if (somalin != 1 || somacol != 1) {
            return 0;
        }
    }
    return 1;
}

int main () {
    int mat[MAX][MAX], n, i, j;

    printf("Digite a ordem da matriz: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\nMATRIZ INSERIDA: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }

    if (matPerm(mat, n)) {
        printf("\nA matriz eh uma matriz de permutacao\n");
    } 
    else {
        printf("\nA matriz nao eh uma matriz de permutacao\n");
    }
    return 0;
}