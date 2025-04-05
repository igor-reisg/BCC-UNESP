#include <stdio.h>
#include <string.h>

void concatenaStrings(char* str1, char* str2, char* resultado) {

    strcpy(resultado, str1);
    strcat(resultado, str2);
}

int main() {
    char prenome[50], sobrenome[50], nomecompleto[100];
    
    printf("Digite o prenome: ");
    fgets(prenome, 50, stdin);

    prenome[strcspn(prenome, "\n")] = 0;

    printf("Digite o sobrenome: ");
    fgets(sobrenome, 50, stdin);
    
    sobrenome[strcspn(sobrenome, "\n")] = 0;

    concatenaStrings(prenome, " ", nomecompleto);
    concatenaStrings(nomecompleto, sobrenome, nomecompleto);

    printf("Nome completo: %s\n", nomecompleto);

    return 0;
}
