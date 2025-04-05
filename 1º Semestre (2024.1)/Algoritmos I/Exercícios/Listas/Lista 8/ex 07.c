#include <stdio.h>

int main() {
    int A[20], i, j;
    long long S = 0;

    printf("Digite os 20 elementos do conjunto A:\n");
    for (i = 0; i < 20; i++) {
        scanf("%d", &A[i]);
    }

    for (i = 0, j = 19; i < 10; i++, j--) {
        S += (long long)(A[i] - A[j]) * (A[i] - A[j]);
    }

    printf("O valor de S é: %lld\n", S);
}
