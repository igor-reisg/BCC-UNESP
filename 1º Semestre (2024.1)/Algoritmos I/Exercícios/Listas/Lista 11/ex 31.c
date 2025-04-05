#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALAVRAS 100

int palavraRepetida(char string[], int *tam) {
    int palavraRep = 0, i;
    char palavraAnt[MAX_PALAVRAS];
    char *palavra = strtok(string, " ");

    while (palavra != NULL) {
    
    for (i = 0; palavra[i] != '\0'; i++) {
        palavra[i] = tolower(palavra[i]);
    }

    if (strcmp(palavra, palavraAnt) == 0) {
        palavraRep++;
    } 
    else {
       strcpy(palavraAnt, palavra);
    }

    palavra = strtok(NULL, " ");
  }

  *tam = 1; 
  return palavraRep;
}

int main() {
  char string[1000];
  int palavraRep;

  printf("Digite uma frase: ");
  fgets(string, sizeof(string), stdin);

  string[strcspn(string, "\n")] = '\0';

  palavraRep = palavraRepetida(string, NULL);

  printf("Número de palavras repetidas: %d\n", palavraRep);

  return 0;
}
