#include <stdio.h>

#define LIN 3
#define COL 13

int main() {
    int palpites[LIN][COL];
    int D = 0, T = 0, V, i, j, valorpago;

    printf("Digite o valor de V: ");
    scanf("%d", &V);

    printf("Digite os palpites (1 para simples, 2 para duplo, 3 para triplo):\n");
   
    for(i = 0; i < LIN; i++) {
        for(j = 0; j < COL; j++) {

            scanf("%d", &palpites[i][j]);
            if (palpites[i][j] == 2) {
                D++;
            } 
            else if (palpites[i][j] == 3) {
                T++;
            }
        }
    }

    valorpago = V * 2 * D * 3 * T;

    printf("Valor a ser pago pelo apostador: %d\n", valorpago);
    printf("Número de palpites duplos: %d\n", D);
    printf("Número de palpites triplos: %d\n", T);

    return 0;
}
