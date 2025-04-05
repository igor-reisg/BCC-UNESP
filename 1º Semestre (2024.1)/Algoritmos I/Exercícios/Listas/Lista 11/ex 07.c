#include <stdio.h>
#include <ctype.h> 

int main() {
    
    char str[1000];
    int qtdpalavra = 0, i;

    printf("Digite a frase: ");
    
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        
        if (!isspace(str[i]) && str[i] != '\0') {
            qtdpalavra++;
        }
    }

    printf("A frase possui %d palavras.\n", qtdpalavra);
    
    return 0;
}
