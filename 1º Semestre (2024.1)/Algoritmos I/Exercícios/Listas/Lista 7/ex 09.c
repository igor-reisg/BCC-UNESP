#include<stdio.h>

int main() {

   int teste = 1, rodada = 1, aldo, beto, a, b, i; 

   scanf("%d", &rodada);

   while(rodada != 0) { 
		
      aldo = 0; beto = 0;

      for(i = 0; i < rodada; i++) {
         
        scanf("%d %d", &a, &b);

        aldo += a;
        beto += b;
      }

      printf("Teste %d\n", teste);
      teste++;

      if (aldo > beto) {
         printf("Aldo\n\n");
      }
      else 
         printf("Beto\n\n");
      
      scanf("%d", &rodada);
   }
}
