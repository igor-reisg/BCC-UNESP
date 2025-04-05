#include <stdio.h>
#include <string.h>


int main() {
   
    char nomes[5][50];
    int i;
   
    printf("Digite 5 nomes:\n");
   
    for (i = 0; i < 5; i++) {
        gets(nomes[i]);
    }
   
   printf("\nNOMES LIDOS:\n");
    for (i = 0; i < 5; i++) {
        puts(nomes[i]);
    }
}
