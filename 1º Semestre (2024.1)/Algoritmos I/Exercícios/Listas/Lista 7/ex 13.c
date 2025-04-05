#include <stdio.h>
#include <math.h>

int main () {

    int L, A, P, R;
    float diametroesfera, diagonaltotal, diagonal;

    scanf("%d %d %d %d", &L, &A, &P, &R);

    diametroesfera = 2*R;

    diagonal = sqrt(pow(L, 2) + pow(P, 2));

    diagonaltotal = sqrt(pow(diagonal, 2) + pow(A, 2));

    if (diagonaltotal <= diametroesfera) {
        printf("S\n");
    }
    else
        printf("N\n");
}