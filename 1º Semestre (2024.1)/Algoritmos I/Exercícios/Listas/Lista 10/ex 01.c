#include <stdio.h>

int main() {
    int N, tempo, total = 0, i; 

    scanf("%d", &N); 

    for (i = 0; i < N; i++) {
        scanf("%d", &tempo); 
        total += tempo; 
    }

    printf("%d\n", total); 

    return 0;
}
