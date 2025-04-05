#include <stdio.h>

int casaValida(char casa) {
    return casa == 'P' || casa == 'C' || casa == 'B' || casa == 'T' || casa == 'Q' || casa == 'R' || casa == 'p' || casa == 'c' || casa == 'b' || casa == 't' || casa == 'q' || casa == 'r' || casa == ' ';
}

int calcularValorTotalPecas(char tabuleiro[8][8]) {
  int valorTotal = 0, i, j, valorpeca, peca, cor;
  int pecaValor[] = {1, 3, 3, 5, 10, 50};

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (casaValida(tabuleiro[i][j])) {
        
            peca = tabuleiro[i][j];
            if(peca >= 'A' && peca <= 'Z')
                cor = 1;
            else
                cor = 0;

            valorpeca = pecaValor[(peca == 'p' || peca == 'P') ? 0 : (peca == 'c' || peca == 'C') ? 1 : (peca == 'b' || peca == 'B') ? 2 : (peca == 't' || peca == 'T') ? 3 : (peca == 'q' || peca == 'Q') ? 4 : 5];

            valorTotal += valorpeca * cor;
            }
        }
    }
    return valorTotal;
}

int main() {

    int valorTotal;

  char tabuleiro[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
  };

    valorTotal = calcularValorTotalPecas(tabuleiro);
    
    printf("Valor total das peças: %d\n", valorTotal);

  return 0;
}
