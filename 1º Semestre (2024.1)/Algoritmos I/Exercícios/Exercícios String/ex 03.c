#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main() {
    char string[50];
    int continuar = 1, i;

    do {
        
        int contA = 0, contE = 0, contI = 0, contO = 0, contU = 0;
        
        printf("Digite uma frase: ");
        gets(string);

        for (i = 0; i < strlen(string); i++) {
            
            string[i] = toupper(string[i]);
            
            switch (string[i]) {
                case 'A':
                    contA++;
                    break;
                case 'E':
                    contE++;
                    break;
                case 'I':
                    contI++;
                    break;
                case 'O':
                    contO++;
                    break;
                case 'U':
                    contU++;
                    break;
            }
        }

        printf("QUANTIDADES DE CADA VOGAL:\nA: %d\nE: %d\nI: %d\nO: %d\nU: %d\n", contA, contE, contI, contO, contU);

        printf("Executar novamente? (1-Sim | 2-Nao): ");
        scanf("%d", &continuar);

        while (continuar != 1 && continuar != 2) {
            printf("Valor invalido. Digite novamente: ");
            scanf("%d", &continuar);
        }
        
        getchar();
        
    } while (continuar == 1);
}
