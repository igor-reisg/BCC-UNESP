#include <stdio.h>
#include <ctype.h>
#include <string.h>

int ehConsoante(char c) {
    
    char c_min = tolower(c);
    
    return (c_min >= 'a' && c_min <= 'z') && !(c_min == 'a' || c_min == 'e' || c_min == 'i' || c_min == 'o' || c_min == 'u');
}

int contarPalavrasIniciadasPorConsoantes(char *str) {
    int contador = 0, dentropalavra = 0;

    while (*str) {
        
        if (isspace(*str)) {
            dentropalavra = 0;
        } 
        else {
            if (!dentropalavra) {
                dentropalavra = 1;
                
                if (ehConsoante(*str)) {
                    contador++;
                }
            }
        }
        str++;
    }
    return contador;
}

int main() {
    char frase[256];
    int tamanho, resultado;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    tamanho = strlen(frase);

    if (tamanho > 0 && frase[tamanho - 1] == '\n') {
        frase[tamanho - 1] = '\0';
    }

    resultado = contarPalavrasIniciadasPorConsoantes(frase);

    printf("Numero de palavras iniciadas por consoantes: %d\n", resultado);

    return 0;
}
