#include <stdio.h>

#define TOLER 1e-6 

#define LIN 100 
#define COL 100 
int main() {
    int lin, col, i, j, solucao; 
    double A[LIN][COL]; 
    double b[LIN]; 
    double x[COL]; 
    double resultado[LIN]; 

    printf("Digite o numero de linhas: ");
    scanf("%d", &lin);
    printf("Digite o numero de colunas: ");
    scanf("%d", &col);

    printf("\nDigite os elementos da matriz A:\n");
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("\nDigite os elementos do vetor b:\n");
    for (i = 0; i < lin; i++) {
        scanf("%lf", &b[i]);
    }

    printf("\nDigite os elementos do vetor x:\n");
    for (i = 0; i < col; i++) {
        scanf("%lf", &x[i]);
    }

    for (i = 0; i < lin; i++) {
        resultado[i] = 0;
        for (j = 0; j < col; j++) {
            resultado[i] += A[i][j] * x[j];
        }
    }

    solucao = 1;
    for (i = 0; i < lin; i++) {
        if (abs(resultado[i] - b[i]) > TOLER) {
            ehSolucao = 0;
            break;
        }
    }
    if (solucao) {
        printf("\nO vetor x é uma solução para o sistema A.x = b.\n");
    } else {
        printf("\nO vetor x não é uma solução para o sistema A.x = b.\n");
    }

    return 0;
}
