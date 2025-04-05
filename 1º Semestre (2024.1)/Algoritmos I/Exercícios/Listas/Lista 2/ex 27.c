#include<stdio.h>
#include<math.h>

int main () {
   
   float x1, x2, y1, y2, dist;
   
   printf("Ponto 1: ");
   scanf("%f %f", &x1, &y1);
   
   printf("Ponto 2: ");
   scanf("%f %f", &x2, &y2);
   
   dist = sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
   
   printf("A distância entre os pontos é de %.2f", dist);
   
}
