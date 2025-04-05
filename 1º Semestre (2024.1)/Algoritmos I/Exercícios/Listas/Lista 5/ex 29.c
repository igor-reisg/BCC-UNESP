#include <stdio.h>

int main() {
  float area, potilum, numlamp, pottot = 0;
  int comodo, clasilum, comp, larg, totlamp = 0;

  printf("Informe o comodo (1 - Quarto, 2 - Sala de TV, 3 - Cozinha, 4 - Varanda, 5 - Escritorio, 6 - Banheiro): ");
  scanf("%d", &comodo);

  printf("Informe a classe de iluminacao (1 ou 2): ");
  scanf("%d", &clasilum);

  printf("Informe o comprimento do comodo: ");
  scanf("%d", &comp);
  printf("Informe a largura do comodo: ");
  scanf("%d", &larg);

  area = comp * larg;

  switch (comodo) {
    case 1: 
      if (clasilum == 1) {
        potilum = area * 15;
        numlamp = potilum / 60;
      } else {
        potilum = area * 20;
        numlamp = potilum / 60;
      }
      break;
    case 2: 
      potilum = area * 18;
      numlamp = potilum / 60;
      break;
    case 3: 
      potilum = area * 18;
      numlamp = potilum / 60;
      break;
    case 4: 
      potilum = area * 18;
      numlamp = potilum / 60;
      break;
    case 5: 
      potilum = area * 20;
      numlamp = potilum / 60;
      break;
    case 6:
      potilum = area * 20;
      numlamp = potilum / 60;
      break;
    default:
      printf("Comodo invalido.\n");
      return 1;
  }

  printf("\nComodo: ");
  switch (comodo) {
    case 1:
      printf("Quarto");
      break;
    case 2:
      printf("Sala de TV");
      break;
    case 3:
      printf("Cozinha");
      break;
    case 4:
      printf("Varanda");
      break;
    case 5:
      printf("Escritorio");
      break;
    case 6:
      printf("Banheiro");
      break;
    default:
      printf("Comodo inválido");
      break;
  }
  printf("\nClasse de iluminacao: %d\n", clasilum);
  printf("Area: %.2f m2\n", area);
  printf("Potencia de iluminacao: %.2f W\n", potilum);
  printf("Numero de lampadas: %.0f\n", numlamp);

  pottot += potilum;
  totlamp += numlamp;

  printf("\nTotal de lampadas: %d\n", totlamp);
  printf("Total de potencia: %.2f W\n", pottot);
}
