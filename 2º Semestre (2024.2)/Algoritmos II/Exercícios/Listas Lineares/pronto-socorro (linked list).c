#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg *node;

struct reg {
    char nome[50];
    char estado[20];
    int idade;
    char genero;
    node next;
};

node criar_paciente(char nome[], char estado[], int idade, char genero) {
    node novo = (node)malloc(sizeof(struct reg));
    strcpy(novo->nome, nome);
    strcpy(novo->estado, estado);
    novo->idade = idade;
    novo->genero = genero;
    novo->next = NULL;
    return novo;
}

void cadastro_paciente(node *lista) {
    char nome[50], estado[20], genero;
    int idade;
    
    printf("\n\nDigite o nome do paciente: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; 
    
    printf("Digite o estado do paciente (regular, ruim, pessimo): ");
    scanf("%s", estado);
    
    printf("Digite a idade do paciente: ");
    scanf("%d", &idade);
    
    getchar(); 
    
    printf("Digite o genero do paciente (M - Masculino | F - Feminino): ");
    scanf("%c", &genero);

    node novo = criar_paciente(nome, estado, idade, genero);

    if (*lista == NULL || 
        (strcmp(novo->estado, "pessimo") == 0 && strcmp((*lista)->estado, "pessimo") != 0) ||
        (strcmp(novo->estado, "ruim") == 0 && strcmp((*lista)->estado, "regular") == 0)) {
        novo->next = *lista;
        *lista = novo;
    } else {
        node atual = *lista;
        while (atual->next != NULL && (
            (strcmp(novo->estado, "pessimo") == 0 && strcmp(atual->next->estado, "pessimo") == 0) ||
            (strcmp(novo->estado, "ruim") == 0 && strcmp(atual->next->estado, "ruim") == 0) ||
            (strcmp(novo->estado, "regular") == 0)
        )) {
            atual = atual->next;
        }
        novo->next = atual->next;
        atual->next = novo;
    }
    printf("Paciente cadastrado com sucesso.\n");
}

void proximo_paciente(node *lista) {
    if (*lista == NULL) {
        printf("Nenhum paciente na fila.\n");
        return;
    }
    node remover = *lista;
    printf("\n\nProximo Paciente:\n");
    printf("Nome: %s\n", remover->nome);
    printf("Idade: %d\n", remover->idade);
    printf("Genero: %c\n", remover->genero);
    printf("Estado: %s\n", remover->estado);

    *lista = remover->next;
    free(remover);
}

void mostrar_lista(node lista) {
    if (lista == NULL) {
        printf("A fila esta vazia.\n");
        return;
    }
    printf("\nLista de Pacientes:\n");
    int i = 1;
    while (lista != NULL) {
        printf("\nPaciente %d:\n", i++);
        printf("Nome: %s\n", lista->nome);
        printf("Idade: %d\n", lista->idade);
        printf("Genero: %c\n", lista->genero);
        printf("Estado: %s\n", lista->estado);
        lista = lista->next;
    }
}

int main() {
    node fila = NULL;
    int opcao;

    do {
        printf("\n-- FICHA DE PACIENTES --\n");
        printf("1. Cadastrar novo paciente\n");
        printf("2. Proximo paciente\n");
        printf("3. Lista de pacientes por estado\n");
        printf("4. Sair\n");
        printf("--> ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastro_paciente(&fila);
                break;
            case 2:
                proximo_paciente(&fila);
                break;
            case 3:
                mostrar_lista(fila);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
