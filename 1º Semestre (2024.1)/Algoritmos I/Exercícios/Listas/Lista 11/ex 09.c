#include <stdio.h>
#include <string.h>


int main() {
   
    char nomes[20][50], aux[50];
    int i, j, quant;
   
    printf("Quantidade de nomes a serem lidos: ");
    scanf("%d", &quant);
   
    for (i = 0; i <= quant; i++) {
        gets(nomes[i]);
    }
       
    for (i = 0; i <= quant; i++) {
       
        for (j = i + 1; j <= quant; j++) {
           
            if (strcmp(nomes[i], nomes[j]) > 0) {
                strcpy(aux, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], aux);
            }
        }
    }
   
    for (i = 0; i <= quant; i++) {
        puts(nomes[i]);
    }
}
