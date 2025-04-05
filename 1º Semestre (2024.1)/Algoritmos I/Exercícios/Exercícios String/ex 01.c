#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main() {
    char string[50];
    int continuar = 1, contvog = 0, i;

    do {
        printf("Digite uma frase: ");
        gets(string);

        for (i = 0; i < strlen(string); i++) {
            
            string[i] = toupper(string[i]);
            
            if (string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U') {
                contvog++;
            }
        }

        printf("A sua frase possui %d vogais\n", contvog);

        printf("Executar novamente? (1-Sim | 2-Nao): ");
        scanf("%d", &continuar);

        while (continuar != 1 && continuar != 2) {
            printf("Valor invalido. Digite novamente: ");
            scanf("%d", &continuar);
        }
        contvog = 0;
        getchar();
        
    } while (continuar == 1);
}
