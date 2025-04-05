#include <stdio.h>

#define N 10 
int M[N][N];

int main() {
    int i, j, num, n, novoI, novoJ;
    
    printf("Digite a ordem da matriz (impar): ");
    scanf("%d", &n);

    while (n % 2 != 1) {
        printf("%d nao eh impar. Digite novamente: ", n);
        scanf("%d", &n);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            M[i][j] = 0;
        }
    }

    i = 1;
    j = 2;  

    for (num = 1; num <= n * n; num++) {
        
        novoI = i - 1;
        novoJ = j + 1;

        if (novoI < 0) {
            novoI = n - 1;
        }
        if (novoJ >= n) {
            novoJ = 0;
        }

        if (M[novoI][novoJ] != 0) {
            novoI = i + 1;
            novoJ = j;
            if (novoI >= n) {
                novoI = 0;
            }
        }

        M[i][j] = num;

        i = novoI;
        j = novoJ;
    }

    printf("Quadrado Magico de ordem %d:\n", n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}
