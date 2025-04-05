#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main() {
    char string[50];
    int continuar = 1, i, cont = 0;

    do {
        printf("Digite uma frase: ");
        gets(string);

        for (i = 0; i < strlen(string); i++) {
            
            if (isupper(string[i])) {
                cont++;
            }
        }

        printf("Quantidade de letras maiusculas: %d\n", cont);

        printf("Executar novamente? (1-Sim | 2-Nao): ");
        scanf("%d", &continuar);

        while (continuar != 1 && continuar != 2) {
            printf("Valor invalido. Digite novamente: ");
            scanf("%d", &continuar);
        }
        
        cont = 0;
        getchar();
        
    } while (continuar == 1);
}
