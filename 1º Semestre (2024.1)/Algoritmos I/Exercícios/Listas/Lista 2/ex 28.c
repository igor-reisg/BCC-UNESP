#include <stdio.h>
#include <math.h>

int main() {
  float r, alt, arealat, areatampa, areatot, litro, lata, custo;

  printf("Digite o raio do tanque: ");
  scanf("%f", &r);
  printf("Digite a altura do tanque: ");
  scanf("%f", &alt);

  arealat = M_PI*r*alt*2;

  areatampa = (M_PI*r*r)*2;

  areatot = arealat + areatampa;

  litro = areatot/3;

  lata = ceil(litro/5);

  custo = lata*50;

  printf("Quantidade de latas de tinta necessarias: %.2f\n", lata);
  printf("Custo total da pintura: R$%.2f\n", custo);
}