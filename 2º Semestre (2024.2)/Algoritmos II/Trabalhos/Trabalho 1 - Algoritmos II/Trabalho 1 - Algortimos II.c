/*
INTEGRANTES: FERNANDO HIROSHI MURUSAKI e IGOR DOS REIS GOMES
SENHA PARA ACESSO: bcc024
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define TAM_MAX 20
#define MAX_DIV 5
#define SETABAIXO 80
#define SETACIMA 72
#define ENTER 13
#define ESC 27

void divisor_string(char string[], char stringdiv[][TAM_MAX], int* contdiv) {
    int i = 0;
    char delimitadores[] = ".,";
    char* divs = strtok(string, delimitadores);

    while (divs != NULL) {
        strncpy(stringdiv[i], divs, TAM_MAX - 1);
        stringdiv[i][TAM_MAX - 1] = '\0';
        divs = strtok(NULL, delimitadores);
        i++;
    }
    *contdiv = i;
}

void escreve_num(char stringdiv[][TAM_MAX], int contdiv) {
    int i, j, tam, num;

    char unidades[][10] = {"zero", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    char dezvinte[][10] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
    char dezenas[][10] = {"vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
    char centenas[][14] = {"cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};
    char ordens_singular[][10] = {"", "mil", "milhao", "bilhao", "trilhao"};
    char ordens_plural[][10] = {"", "mil", "milhoes", "bilhoes", "trilhoes"};

    for (i = 0; i < contdiv; i++) {
        tam = strlen(stringdiv[i]);

        for (j = 0; j < tam; j++) {
            num = stringdiv[i][j] - '0';

            if (tam == 3) {
                if (j == 0) {
                    if (num == 1 && (stringdiv[i][1] == '0' && stringdiv[i][2] == '0')) {
                        printf("cem");
                        break;
                    } else {
                        printf("%s", centenas[num - 1]);
                        if (stringdiv[i][1] != '0' || stringdiv[i][2] != '0') {
                            printf(" e ");
                        }
                    }
                } else if (j == 1) {
                    if (num == 1) {
                        printf("%s", dezvinte[stringdiv[i][2] - '0']);
                        break;
                    } else if (num > 1) {
                        printf("%s", dezenas[num - 2]);
                        if (stringdiv[i][2] != '0') {
                            printf(" e ");
                        }
                    }
                } else if (j == 2) {
                    if (stringdiv[i][1] != '1' && stringdiv[i][2] != '0') {
                        printf("%s", unidades[num]);
                    }
                }
            } else if (tam == 2) {
                if (j == 0) {
                    if (num == 1) {
                        printf("%s", dezvinte[stringdiv[i][1] - '0']);
                        break;
                    } else if (num > 1) {
                        printf("%s", dezenas[num - 2]);
                        if (stringdiv[i][1] != '0') {
                            printf(" e ");
                        }
                    }
                } else if (j == 1) {
                    if (stringdiv[i][0] != '1' && stringdiv[i][1] != '0') {
                        printf("%s", unidades[num]);
                    }
                }
            } else if (tam == 1) {
                printf("%s", unidades[num]);
            }
        }

        if (i < contdiv - 1) {
            int ordem = contdiv - i - 2;
            int valor = atoi(stringdiv[i]);
            if (valor > 0) {
                if (valor == 1) {
                    printf(" %s", ordens_singular[ordem]);
                } else {
                    printf(" %s", ordens_plural[ordem]);
                }
            }
            if (i < contdiv - 2) {
                printf(" e ");
            }
        }

        if (i == contdiv - 2 && contdiv > 1) {
            printf("reais ");
            if (stringdiv[i][1] != '0') {
                printf("e ");
            }
        } else if (contdiv == 1) {
            printf(" reais");
        }
    }

    if (contdiv > 1) {
        int centavos = atoi(stringdiv[contdiv - 1]);
        if (centavos > 0) {
            printf(" centavo%s", centavos > 1 ? "s" : "");
        } else {
            printf("zero centavos");
        }
    }
    printf("\n");
}

int SetColor(WORD color) {
    HANDLE a;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    return SetConsoleTextAttribute(a, color);
}

void gotoxy(int x, int y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void centralizar_texto(const char* texto, int linha) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int largura_terminal = csbi.dwSize.X;
    int comprimento = strlen(texto);
    int espaco = (largura_terminal - comprimento) / 2;
    gotoxy(espaco, linha);
    printf("%s\n", texto);
}

void textoMenu(const char string[], WORD cor, int linha) {
    SetColor(cor);
    centralizar_texto(string, linha);
    SetColor(15);
}

void menu(int opcao) {
    int i;
    char *vet[] = {
        "1. Escrever valor por extenso",
        "2. Sair",
        "3. Ajuda"
    };

    system("cls");
    centralizar_texto("=== PROGRAMA DE ESCRITA POR EXTENSO ===", 2);

    for (i = 0; i < 3; i++) {
        if (i == opcao - 1) {
            textoMenu(vet[i], 4, 4 + i);
        } else {
            textoMenu(vet[i], 15, 4 + i);
        }
    }
}

void ajuda() {
    centralizar_texto("3. Ajuda: Use as setas para cima e para baixo para navegar no menu e Enter para selecionar. Pressione qualquer tecla para voltar", 6);
}

int main() {
    int valido, tam;
    char string[TAM_MAX];
    char stringdiv[MAX_DIV][TAM_MAX];
    int contdiv = 0, opcao = 1; 
    char senha[11], tecla;

    printf("Digite a senha para acessar o sistema: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0'; 

    if (strcmp(senha, "bcc024") == 0) {
        do {
            do {
                menu(opcao);
                tecla = getch();

                if (tecla <= 0) {
                    tecla = getch();
            
                    if (tecla == SETACIMA) {
                        if (opcao > 1) {
                            opcao--;
                        } else {
                            opcao = 3;
                        }
                    } else if (tecla == SETABAIXO) {
                        if (opcao < 3) {
                            opcao++;
                        } else {
                            opcao = 1;
                        }
                    }
                } else if (tecla == ENTER) {
                    switch (opcao) {
                        case 1:
                            printf("Pontos obrigatorios para separar as grandezas.\n(xxx.xxx.xxx.xxx,xx)\nDigite seu saldo no formato acima: R$ ");
                            if (fgets(string, sizeof(string), stdin) != NULL) {
                                tam = strlen(string);
                                if (tam > 0 && string[tam - 1] == '\n') {
                                    string[tam - 1] = '\0';
                                }

                                do {
                                    valido = 1;
                                    for (int i = 0; string[i] != '\0'; i++) {
                                        if (string[i] != '0' && string[i] != '1' && string[i] != '2' &&
                                            string[i] != '3' && string[i] != '4' && string[i] != '5' &&
                                            string[i] != '6' && string[i] != '7' && string[i] != '8' &&
                                            string[i] != '9' && string[i] != ',' && string[i] != '.') {
                                            printf("Caractere invalido detectado, digite novamente.\n\n");
                                            printf("Pontos obrigatorios para separar as grandezas.\n(xxx.xxx.xxx.xxx,xx)\nDigite seu saldo no formato acima: R$ ");
                                            if (fgets(string, sizeof(string), stdin) != NULL) {
                                                tam = strlen(string);
                                                if (tam > 0 && string[tam - 1] == '\n') {
                                                    string[tam - 1] = '\0';
                                                }
                                            } else {
                                                printf("Erro ao ler a entrada.\n");
                                                return 1;
                                            }
                                            valido = 0;
                                            break;
                                        }
                                    }
                                } while (!valido);

                                do {
                                    valido = 1;
                                    for (int i = 0; string[i] != '\0'; i++) {
                                        if (string[i] == '.' || string[i] == ',') {
                                            if (i > 0 && (string[i-1] == '.' || string[i-1] == ',')) {
                                                printf("Formato incorreto, digite novamente.\n\n");
                                                printf("Pontos obrigatorios para separar as grandezas.\n(xxx.xxx.xxx.xxx,xx)\nDigite seu saldo no formato acima: R$ ");
                                                if (fgets(string, sizeof(string), stdin) != NULL) {
                                                    int tam = strlen(string);
                                                    if (tam > 0 && string[tam - 1] == '\n') {
                                                        string[tam - 1] = '\0';
                                                    }
                                                } else {
                                                    printf("Erro ao ler a entrada.\n");
                                                    return 1;
                                                }
                                                valido = 0;
                                                break;
                                            }
                                        }
                                    }
                                } while (!valido);
                                
                                do {
                                    valido = 1;
                                    for (int i = 0; string[i] != '\0'; i++) {
                                        if (string[i] == ',' && string[i+3] != '\0') {
                                            printf("Utilize somente duas casas decimais a partir da virgula.\n\n");
                                            printf("Pontos obrigatorios para separar as grandezas.\n(xxx.xxx.xxx.xxx,xx)\nDigite seu saldo no formato acima: R$ ");
                                            if (fgets(string, sizeof(string), stdin) != NULL) {
                                                int tam = strlen(string);
                                                if (tam > 0 && string[tam - 1] == '\n') {
                                                    string[tam - 1] = '\0';
                                                }
                                            } else {
                                                printf("Erro ao ler a entrada.\n");
                                                return 1;
                                            }
                                            valido = 0;
                                            break;
                                        }
                                    }
                                } while (!valido);

                                divisor_string(string, stringdiv, &contdiv);
                                printf("\nValor por extenso: ");
                                escreve_num(stringdiv, contdiv);
                                printf("\nPressione ENTER para voltar ao menu...");
                                while (getch() != ENTER) {
                                }
                            } else {
                                printf("Erro ao ler a entrada.\n");
                            }
                            break;
                        
                        case 2:
                            printf("Saindo...\n");
                            exit(0);
                            break;
                        
                        case 3:
                            ajuda();
                            while (getch() != ENTER) {
                            }
                            break;
                    }
                }
            } while (tecla != ESC && opcao != 2);
        } while (tecla != ESC); 
    } else {
        printf("Senha incorreta! Acesso negado.\n");
    }
    return 0;
}
