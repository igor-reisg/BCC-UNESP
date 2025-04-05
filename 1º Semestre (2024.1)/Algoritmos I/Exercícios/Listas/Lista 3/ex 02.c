#include<stdio.h>
#include<math.h>

int main () {

    int n, hanoi, teste = 0;

    scanf("%d", &n);

    while (n != 0) {
    
        if (n != 0) {

            teste++;
            hanoi = 0;
        
            hanoi = pow(2, n) - 1;

            printf("Teste %d\n%d\n\n", teste, hanoi);

            scanf("%d", &n);
        }
    }
}