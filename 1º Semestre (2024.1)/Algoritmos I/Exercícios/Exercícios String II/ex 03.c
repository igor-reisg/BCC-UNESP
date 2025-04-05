#include <stdio.h>
#include <string.h>

int main () {

    char string[100];
    int ocorrencia[256] = {0}, i;
    
    printf("Digite uma string: ");
    gets(string);

    for (i = 0; i < (int)strlen(string); i++) {

        ocorrencia[(unsigned char)string[i]]++;
    }

    printf("\nTabela de ocorrencias de caracteres:\n");
    printf("Caractere | Ocorrencias\n");

    for (i = 0; i < 256; i++) {
        
        if (ocorrencia[i] > 0) {
            printf("    %c     |     %d\n", i, ocorrencia[i]);
        }
    }

}