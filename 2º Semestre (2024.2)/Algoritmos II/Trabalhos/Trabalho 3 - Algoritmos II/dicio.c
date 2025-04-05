/*TRABALHO 3 DE ALG 2;
ALUNOS:
MURILO TOMAZ GONZAGA
IGOR DOS REIS GOMES
FERNANDO HIROSHI MUROSAKI
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 1000

void conc(int lcase, char *newstr, char *token) {
    if (lcase == 0) {
        strcat(newstr, token);
        strcat(newstr, " ");
    } else if (lcase == 1) {
        strcat(newstr, token);
        strcat(newstr, " ");
        newstr[0] = toupper(newstr[0]);
    } else if (lcase == 2) {
        strcat(newstr, token);
        strcat(newstr, " ");
        for (int i = 0; i < strlen(newstr); i++) {
            if(isalpha(newstr[i])){
              newstr[i] = toupper(newstr[i]);
            }
        }
    }
}


void leitura(FILE *file, FILE *origem, FILE *temp){
    char newstr[MAX], str[MAX];

    while (fscanf(origem, "%s", str) != EOF) {
       
        char *token = strtok(str, " ");
        newstr[0] = '\0'; 

        while (token != NULL) {
            char buffer1[256], buffer2[256], cmpstr[100];
            int flag = 0, lcase = 0;

            strcpy(cmpstr, token);
            if (islower(token[0])) {
                lcase = 0;
            } else if (isupper(token[0]) && !isupper(token[1])) {
                lcase = 1;
            } else if (strcmp(token, strupr(token)) == 0) {
                lcase = 2;
            }
            
            strlwr(token);
            rewind(file);

            while (fscanf(file, "%s %s", buffer1, buffer2) == 2) {
                if (strcmp(token, buffer1) == 0) {
                    conc(lcase, newstr, buffer2);
                    flag = 1;
                    break;
                } else if (strcmp(token, buffer2) == 0) {
                    conc(lcase, newstr, buffer1);
                    flag = 1;
                    break;
                }
            }

            if (!flag) {
                strcat(newstr, cmpstr);
                strcat(newstr, " ");
            }

            token = strtok(NULL, " ");
        }

        fprintf(temp, "%s", newstr);
        printf("%s", newstr); 
    }
}


int main() {
    int z = 1;

    while (z) {
        int n = MAX;  
        char name[50];

        printf("Digite o nome do arquivo que deseja transcrever (sem o .txt): ");
        fgets(name, n, stdin);
        name[strcspn(name, "\n")] = '\0'; 
        
        strcpy(name,strcat(name, ".txt"));

        FILE *origem = fopen(name, "r");
        FILE *file = fopen("dicionario.txt", "r");
        FILE *temp = fopen("temp.txt", "w");
        
        if (file == NULL || origem == NULL || temp == NULL ) {
            printf("Erro ao abrir um ou mais arquivos. Reinicie o programa e verifique as files\n");
            exit(1);
        }
        
        printf("\n");
        leitura(file, origem, temp);
        
        fclose(file);
        fclose(origem);
        fclose(temp);

        remove(name);
        rename("temp.txt", name);

        printf("\n\nDigite 1 para continuar o programa ou 0 para encerrar: ");
        scanf("%d", &z);
        getchar();  
    }

    return 0;
}