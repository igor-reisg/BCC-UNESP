#include<stdio.h>
#include<math.h>

int main () {

    int i, teste = 0, n, pedpapel, qtdobra, corte;

    scanf("%d", &n);

    while (n != -1) {

        if (n != -1) {

            pedpapel = 2;
            qtdobra = 1;
            teste++;
            
            for (i = 1; i <= n; i++) {

                pedpapel += qtdobra;
                qtdobra *= qtdobra;
            }
            
            corte = pow(pedpapel, 2);

            printf("Teste %d\n%d\n\n", teste, corte);

            scanf("%d", &n);
        }
    }
}