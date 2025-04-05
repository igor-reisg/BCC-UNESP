// --------------------------------------
// ALUNOS:
// Fernando Hiroshi Murosaki
// Igor dos Reis Gomes
// --------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define AC_BLACK "\x1b[30m"
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN "\x1b[36m"
#define AC_WHITE "\x1b[37m"
#define AC_NORMAL "\x1b[m"

#define seta 224
#define cima 72
#define baixo 80
#define enter 13
#define esc 27

char* filename = "agenda.txt";

typedef struct Reg *No;
struct Reg {
    int dia, mes, ano, hora, minuto;
    char descricao[81];
    struct Reg *prox;
    struct Reg *ant;
};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printTitle(char* title) {
    printf("%s\n", AC_CYAN);
    for (int i = 0; i < 40; i++) {
        printf("=");
    }
    printf("\n");
    printf("         %s%s%s\n", AC_YELLOW, title, AC_CYAN);
    for (int i = 0; i < 40; i++) {
        printf("=");
    }
    printf("\n%s", AC_NORMAL);
}

void saveToFile(No *Lista) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    No current = *Lista;
    while (current) {
        fprintf(file, "%d;%d;%d;%d;%d;%s\n", 
                current->dia, current->mes, current->ano, 
                current->hora, current->minuto, current->descricao);
        current = current->prox;
    }

    fclose(file);
    printf("\n\nCompromissos salvos com sucesso no arquivo '%s'.\n", filename);
}

void insereCompromissoAutoOrdenadoData
(No *Lista, int dia, int mes, int ano, int hora, int minuto, char descricao[]) {

    No p = (No)malloc(sizeof(struct Reg));
    No r = *Lista;

    p->dia = dia;
    p->mes = mes;
    p->ano = ano;
    p->hora = hora;
    p->minuto = minuto;
    strcpy(p->descricao, descricao);

    if (p == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    p->prox = NULL;
    p->ant = NULL;

    if (*Lista == NULL) {
        *Lista = p;
        return;
    }

    while (r != NULL) {
        if (p->ano < r->ano || 
            (p->ano == r->ano && p->mes < r->mes) || 
            (p->ano == r->ano && p->mes == r->mes && p->dia < r->dia) || 
            (p->ano == r->ano && p->mes == r->mes && p->dia == r->dia && p->hora < r->hora) || 
            (p->ano == r->ano && p->mes == r->mes && p->dia == r->dia && p->hora == r->hora && p->minuto <= r->minuto)) {

            if (r->ant == NULL) {
                p->prox = r;
                r->ant = p;
                *Lista = p;
                return;
            }

            p->prox = r;
            p->ant = r->ant;
            r->ant->prox = p;
            r->ant = p;
            return;
        }

        r = r->prox;
    }

    r = *Lista;
    while (r->prox != NULL) {
        r = r->prox;
    }

    r->prox = p;
    p->ant = r;
}

void insereCompromissoManualOrdenadoData(No *Lista) {
    No p = (No)malloc(sizeof(struct Reg));
    No r = *Lista;

    if (p == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }
    
    system("cls");
    printf("\n\nQual seria o compromisso?\n\n-> ");
    fgets(p->descricao, 81, stdin);
    p->descricao[strcspn(p->descricao, "\n")] = '\0';
    system("cls");

    printf("[%sdd%s/mm/yyyy] [hh/mm]\n\n", AC_RED, AC_NORMAL);
    printf("Insira o dia do compromisso:\n\n-> ");
    scanf("%d", &p->dia);
    system("cls");

    printf("[%d/%smm%s/yyyy] [hh/mm]\n\n",p->dia, AC_RED, AC_NORMAL);
    printf("Insira o mes do compromisso:\n\n-> ");
    scanf("%d", &p->mes);
    system("cls");

    printf("[%d/%d/%syyyy%s] [hh/mm]\n\n",p->dia, p->mes, AC_RED, AC_NORMAL);
    printf("Insira o ano do compromisso:\n\n-> ");
    scanf("%d", &p->ano);
    system("cls");

    printf("[%d/%d/%d] [%shh%s/mm]\n\n",p->dia, p->mes, p->ano, AC_RED, AC_NORMAL);
    printf("Insira a hora do compromisso:\n\n-> ");
    scanf("%d", &p->hora);
    system("cls");

    printf("[%d/%d/%d] [%d/%smm%s]\n\n",p->dia, p->mes, p->ano, p->hora, AC_RED, AC_NORMAL);
    printf("Insira o minuto do compromisso:\n\n-> ");
    scanf("%d", &p->minuto);

    p->prox = NULL;
    p->ant = NULL;

    if (*Lista == NULL) {
        *Lista = p;
        return;
    }

    while (r != NULL) {
        if (p->ano < r->ano || 
            (p->ano == r->ano && p->mes < r->mes) || 
            (p->ano == r->ano && p->mes == r->mes && p->dia < r->dia) || 
            (p->ano == r->ano && p->mes == r->mes && p->dia == r->dia && p->hora < r->hora) || 
            (p->ano == r->ano && p->mes == r->mes && p->dia == r->dia && p->hora == r->hora && p->minuto <= r->minuto)) {

            if (r->ant == NULL) {
                p->prox = r;
                r->ant = p;
                *Lista = p;
                return;
            }

            p->prox = r;
            p->ant = r->ant;
            r->ant->prox = p;
            r->ant = p;
            return;
        }

        r = r->prox;
    }

    r = *Lista;
    while (r->prox != NULL) {
        r = r->prox;
    }

    r->prox = p;
    p->ant = r;

    printf("\nCompromisso inserido com sucesso!\n");
}

void loadFromFile(No *Lista) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Nenhum arquivo de compromissos encontrado ou erro ao abrir o arquivo.\n");
        return;
    }

    char line[200];
    int dia, mes, ano, hora, minuto;
    char descricao[81];

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%d;%d;%d;%d;%d;%[^\n]", &dia, &mes, &ano, &hora, &minuto, descricao) == 6) {
            insereCompromissoAutoOrdenadoData(Lista, dia, mes, ano, hora, minuto, descricao);
        } 
        else 
            printf("\nLinha mal formatada encontrada no arquivo e ignorada: %s\n\n", line);
    }

    fclose(file);
    printf("\nCompromissos carregados com sucesso do arquivo '%s'.\n\n", filename);
}

void mostraCompromisso(No *Lista, int pos) {
    No p = *Lista;
    int cont = 1;

    if (!p) {
        printf("A lista de compromissos esta vazia.\n");
        return;
    }

    while (p != NULL && cont < pos) {
        p = p->prox;
        cont++;
    }

    if (!p) {
        printf("Posicao %d invalida. A lista contem apenas %d compromisso(s).\n", pos, cont - 1);
        return;
    }

    printf("- - - - - - - - - - - - - - - - - - - -\n");
    printf("Compromisso n%c %d.\n",167, cont);
    printf("\"%s\"\n", p->descricao);
    printf("Data: %02d/%02d/%04d\n", p->dia, p->mes, p->ano);
    printf("Hora: %02d:%02d\n", p->hora, p->minuto);
    printf("- - - - - - - - - - - - - - - - - - - -\n");
}

void removerCompromissoPorDataHorario(No *Lista) {

    No r = *Lista;
    int dia, mes, ano, hora, minuto;

    system("cls");

    printf("[%sdd%s/mm/yyyy] [hh/mm]\n\n", AC_RED, AC_NORMAL);
    printf("Insira o dia do compromisso:\n\n-> ");
    scanf("%d", &dia);
    system("cls");

    printf("[%d/%smm%s/yyyy] [hh/mm]\n\n",dia, AC_RED, AC_NORMAL);
    printf("Insira o mes do compromisso:\n\n-> ");
    scanf("%d", &mes);
    system("cls");

    printf("[%d/%d/%syyyy%s] [hh/mm]\n\n",dia, mes, AC_RED, AC_NORMAL);
    printf("Insira o ano do compromisso:\n\n-> ");
    scanf("%d", &ano);
    system("cls");

    printf("[%d/%d/%d] [%shh%s/mm]\n\n",dia, mes, ano, AC_RED, AC_NORMAL);
    printf("Insira a hora do compromisso:\n\n-> ");
    scanf("%d", &hora);
    system("cls");

    printf("[%d/%d/%d] [%d/%smm%s]\n\n",dia, mes, ano, hora, AC_RED, AC_NORMAL);
    printf("Insira o minuto do compromisso:\n\n-> ");
    scanf("%d", &minuto);

    while (r != NULL) {
        if (r->dia == dia && r->mes == mes && r->ano == ano && r->hora == hora && r->minuto == minuto) {
            if (r->ant != NULL) r->ant->prox = r->prox;
            if (r->prox != NULL) r->prox->ant = r->ant;

            if (r == *Lista) *Lista = r->prox;

            free(r);
            printf("\nCompromisso removido com sucesso.\n\n");
            return;
        }
        r = r->prox;
    }
    
    printf("\nCompromisso nao encontrado.\n\n");
}

void removerCompromissoPorPalavraChave(No *Lista) {
    No r = *Lista;
    char palavra[81];
    int encontrou = 0;

    system("cls");

    printf("Digite a palavra chave:\n");
    fgets(palavra, 81, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    while (r != NULL) {
        if (strstr(r->descricao, palavra) != NULL) {
            encontrou = 1;
            if (r->ant != NULL) r->ant->prox = r->prox;
            if (r->prox != NULL) r->prox->ant = r->ant;

            if (r == *Lista) *Lista = r->prox;

            free(r);
            printf("\nCompromisso contendo '%s' removido com sucesso.\n", palavra);
            return;
        }
        r = r->prox;
    }

    if(!encontrou) {
        printf("\nNenhum compromisso encontrado contendo '%s'.\n", palavra);
    }
}

void consultarCompromissosPorData(No *Lista) {
    No r = *Lista;

    int pos = 1;

    int dia, mes, ano;

    system("cls");

    printf("[%sdd%s/mm/yyyy] [hh/mm]\n\n", AC_RED, AC_NORMAL);
    printf("Insira o dia do compromisso:\n\n-> ");
    scanf("%d", &dia);
    system("cls");

    printf("[%d/%smm%s/yyyy] [hh/mm]\n\n",dia, AC_RED, AC_NORMAL);
    printf("Insira o mes do compromisso:\n\n-> ");
    scanf("%d", &mes);
    system("cls");

    printf("[%d/%d/%syyyy%s] [hh/mm]\n\n",dia, mes, AC_RED, AC_NORMAL);
    printf("Insira o ano do compromisso:\n\n-> ");
    scanf("%d", &ano);
    system("cls");

    while (r != NULL) {
        if (r->dia == dia && r->mes == mes && r->ano == ano) {
            mostraCompromisso(Lista, pos);
        }
        pos++;
        r = r->prox;
    }

    if (pos == 1) {
        printf("\nNenhum compromisso encontrado na data %02d/%02d/%04d.\n\n", dia, mes, ano);
    }
}

void procurarCompromissoPorPalavraChave(No *Lista) {
    No r = *Lista;
    int encontrou = 0;

    char palavra[81];

    system("cls");
    printf("Digite a palavra chave:");
    fgets(palavra, 81, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    printf("\n\n");
    while (r != NULL) {
        if (strstr(r->descricao, palavra) != NULL) {
            printf("%02d/%02d/%04d %02d:%02d - %s\n", r->dia, r->mes, r->ano, r->hora, r->minuto, r->descricao);
            encontrou = 1;
        }
        r = r->prox;
    }

    if (!encontrou) {
        printf("\nNenhum compromisso encontrado contendo '%s'.\n\n", palavra);
    }
}

void alterarCompromissoPorPalavraChave(No *Lista) {
    No r = *Lista;
    int encontrou = 0;
    char palavra[81];

    system("cls");
    printf("Digite palavra-chave:\n");
    fgets(palavra, 81, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    char novaDescricao[81];

    while (r != NULL) {
        if (strstr(r->descricao, palavra) != NULL) {
            encontrou = 1;
            printf("Compromisso encontrado!\n\n");

            printf("Digite a nova descricao:\n");
            fgets(novaDescricao, 81, stdin);

            palavra[strcspn(palavra, "\n")] = '\0';
            strcpy(r->descricao, novaDescricao);
            printf("\nCompromisso atualizado para: %s\n\n", novaDescricao);
            return;
        }
        r = r->prox;
    }

    if (!encontrou) {
        printf("Nenhum compromisso encontrado contendo '%s'.\n\n", palavra);
    }
}

void alterarCompromissoPorDataHorario(No *Lista) {

    No r = *Lista;
    int encontrou = 0;
    int dia, mes, ano, hora, minuto;
    char novaDescricao[81];

    system("cls");
    printf("[%sdd%s/mm/yyyy] [hh/mm]\n\n", AC_RED, AC_NORMAL);
    printf("Insira o dia do compromisso:\n\n-> ");
    scanf("%d", &dia);
    system("cls");

    printf("[%d/%smm%s/yyyy] [hh/mm]\n\n",dia, AC_RED, AC_NORMAL);
    printf("Insira o mes do compromisso:\n\n-> ");
    scanf("%d", &mes);
    system("cls");

    printf("[%d/%d/%syyyy%s] [hh/mm]\n\n",dia, mes, AC_RED, AC_NORMAL);
    printf("Insira o ano do compromisso:\n\n-> ");
    scanf("%d", &ano);
    system("cls");

    printf("[%d/%d/%d] [%shh%s/mm]\n\n",dia, mes, ano, AC_RED, AC_NORMAL);
    printf("Insira a hora do compromisso:\n\n-> ");
    scanf("%d", &hora);
    system("cls");

    printf("[%d/%d/%d] [%d/%smm%s]\n\n",dia, mes, ano, hora, AC_RED, AC_NORMAL);
    printf("Insira o minuto do compromisso:\n\n-> ");
    scanf("%d", &minuto);

    while (r != NULL) {
        if (r->dia == dia && r->mes == mes && r->ano == ano && r->hora == hora && r->minuto == minuto) {
            encontrou = 1;
            printf("Compromisso encontrado!\n\n");

            printf("Digite a nova descricao:\n");
            fgets(novaDescricao, 81, stdin);

            strcpy(r->descricao, novaDescricao);
            printf("Compromisso em %02d/%02d/%04d %02d:%02d atualizado para: %s\n", dia, mes, ano, hora, minuto, novaDescricao);
            return;
        }
        r = r->prox;
    }
    if (!encontrou) {
        printf("Nenhum compromisso encontrado em %02d/%02d/%04d %02d:%02d.\n", dia, mes, ano, hora, minuto);
    }
}

void printMenu(int selecionado) {
    printTitle("AGENDA DE HIROSHI E IGOR");
    
    const char* options[] = {
        "1. Adicionar compromisso",
        "2. Remover compromisso por data e horario",
        "3. Remover compromisso por palavra-chave",
        "4. Consultar compromissos por data",
        "5. Procurar compromisso por palavra-chave",
        "6. Alterar compromisso por palavra-chave",
        "7. Alterar compromisso por data e horario",
        "8. Salvar mudancas no arquivo",
        "9. Carregar compromissos do arquivo",
        "10. Sair"
    };

    for (int i = 0; i < 10; i++) {
        if (i == selecionado) {
            printf("%s> %s%s\n", AC_BLUE, options[i], AC_NORMAL); 
        } 
        else {
            printf("  %s\n", options[i]);
        }
    }
}

void menu(No *Lista) {
    int choice = 0; 
    int key = 0;

    do {
        system("cls");
        printMenu(choice);

        key = getch();

        if (key == seta) { 
            key = getch();  
            if (key == cima && choice > 0) {
                choice--;
            } 
            else if (key == baixo && choice < 9) {
                choice++;  
            }
        } 
        else if (key == enter) {
            switch (choice) {
                case 0: insereCompromissoManualOrdenadoData(Lista); break;
                case 1: removerCompromissoPorDataHorario(Lista); break;
                case 2: removerCompromissoPorPalavraChave(Lista); break;
                case 3: consultarCompromissosPorData(Lista); break;
                case 4: procurarCompromissoPorPalavraChave(Lista); break;
                case 5: alterarCompromissoPorPalavraChave(Lista); break;
                case 6: alterarCompromissoPorDataHorario(Lista); break;
                case 7: saveToFile(Lista); break;
                case 8: loadFromFile(Lista); break;
                case 9: printf("Saindo..."); return;
            }

            getchar();
            printf("\nPressione Enter para continuar...");
            getchar();
        }

    } while (key != esc);
}

int main() {
    No Lista1 = NULL;
    menu(&Lista1);
}