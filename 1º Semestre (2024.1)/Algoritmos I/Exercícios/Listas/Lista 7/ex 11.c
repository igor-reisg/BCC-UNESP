#include <stdio.h>

int main () {
    int n, k, i, tamfatia, paes[10000], esq, dir, meio, total = 0;
    
    scanf ("%d %d", &n, &k);
    
    for (i = 0; i < k; i++) {
      scanf ("%d", &paes[i]);
    }
    
    tamfatia = 0;
    esq = 0;
    dir = 10000 + 1;
    
    while (esq <= dir) {
      
      meio = (esq + dir) / 2; 
      
      total = 0;

      for (i = 0; i < k; i++) { 
        total += paes[i] / meio;
      }
      
      if (total >= n) {
        
        esq = meio + 1;
        tamfatia = meio;
      } 
      else 
        dir = meio - 1;
    }
    printf ("%d\n", tamfatia);
}


