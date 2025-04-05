#include <stdio.h>
#include <math.h>

int main () {

    int x1, x2, y1, y2;
    float dist;

    printf("\nCALCULO DA DISTANCIA ENTRE DOIS PONTOS\nDigite o par ordenado do ponto P: ");
    scanf("%d %d", &x1, &y1);

    printf("Digite o par ordenado do ponto Q: ");
    scanf("%d %d", &x2, &y2);

    dist = sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));

    printf("A distancia entre os pontos P e Q eh %.2f", dist);

}