#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main() {
    char string[50];
    int continuar = 1, i;
    int tam = strlen(string);

    do {
        printf("Digite uma frase: ");
        gets(string);

        for (i = 0; i < tam; i++) {
            
            if (toupper(string[i]) == 'A' || toupper(string[i]) == 'E' || toupper(string[i]) == 'I' || toupper(string[i]) == 'O' || toupper(string[i]) == 'U') {
                string[i] = '*';
            }
        }

        printf("NOVA FRASE: %s\n", string);

        printf("Executar novamente? (1-Sim | 2-Nao): ");
        scanf("%d", &continuar);

        while (continuar != 1 && continuar != 2) {
            printf("Valor invalido. Digite novamente: ");
            scanf("%d", &continuar);
        }
        
        getchar();
        
    } while (continuar == 1);
}
