#include <stdio.h>
#define max 15

int main() {
    
    int n, i, j, mat[max][max], somalinha, somacol, somadiagprinc, somadiagsec, magico = 1, somamagico = 0;

    printf("Digite o tamanho da matriz (n x n): ");
    scanf("%d", &n);
    
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    for (j = 0; j < n; j++) {
        somamagico += mat[0][j];
    }

    for (i = 1; i < n && magico; i++) {
        somalinha = 0;
        for (j = 0; j < n; j++) {
            somalinha += mat[i][j];
        }
        if (somalinha != somamagico) {
            magico = 0;
        }
    }

    for (i = 0; i < n && magico; i++) {
        somacol = 0;
        for (j = 0; j < n; j++) {
            somacol += mat[j][i];
        }
        if (somacol != somamagico) {
            magico = 0;
        }
    }

    if (magico) {
        somadiagprinc = 0;
        for (i = 0; i < n; i++) {
            somadiagprinc += mat[i][i];
        }
        if (somadiagprinc != somamagico) {
            magico = 0;
        }
    }

    if (magico) {
        somadiagsec = 0;
        for (i = 0; i < n; i++) {
            somadiagsec += mat[i][n - i - 1];
        }
        if (somadiagsec != somamagico) {
            magico = 0;
        }
    }

    if (magico) {
        printf("A matriz eh um quadrado magico.\n");
    } else {
        printf("A matriz nao eh um quadrado magico.\n");
    }
}
