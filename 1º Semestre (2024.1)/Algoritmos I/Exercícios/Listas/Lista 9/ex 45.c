#include <stdio.h>

#define MAX 100

int quadMag(int mat[][MAX], int n) {
    int i, j, somadiag = 0, soma = 0;
    
    for (i = 0; i < n; i++) {
        somadiag += mat[i][i];
    }
    for (i = 0; i < n; i++) {
        soma = 0;
        for (j = 0; j < n; j++) {
            soma += mat[i][j];
        }
        if (soma != somadiag) {
            return 0;
        }
    }
    for (j = 0; j < n; j++) {
        soma = 0;
        for (i = 0; i < n; i++) {
            soma += mat[i][j];
        }
        if (soma != somadiag) {
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

    if (quadMag(mat, n)) {
        printf("\nA matriz eh um quadrado magico\n");
    } 
    else {
        printf("\nA matriz nao eh um quadrado magico\n");
    }
    return 0;
}