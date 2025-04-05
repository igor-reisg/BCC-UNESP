#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct reg *node;

struct reg {
    int val;
    node next;
};

void iniciar_lista(node *lista) {
    *lista = NULL;
}

void inserir_inicio(node *lista, int val) {
    node p = (node)malloc(sizeof(struct reg));

    p->val = val;
    p->next = *lista;
    *lista = p;
}

void inserir_fim(node *lista, int value) {
    node p = (node)malloc(sizeof(struct reg));

    p->val = value;
    p->next = NULL;

    if (*lista == NULL) {
        *lista = p;
    }

    node q;
    while(q->next != NULL) {
        q = q->next;
    }
    q->next = p;
}

void remover_inicio(node *lista) {

    if (*lista == NULL) {
        return;
    }

    if ((*lista)->next == NULL) {
        free(*lista);
        *lista = NULL;
    }
    else {
        node p = *lista, q;
        q = p;
        p = p->next;
        free(q);
    }
}

void remover_fim(node *lista) {
    if (*lista == NULL) {
        return;
    }
    
    if ((*lista)->next == NULL) {
        free(*lista);
        *lista = NULL;
    }
    else {
        node p = *lista, q;
        while(p->next != NULL) {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        free(p);
    }
}

int main() {
    node lista1, lista2;
    char continuar;
    int escolha, value;

    iniciar_lista(&lista1);
    iniciar_lista(&lista2);

    do {
        printf("-- Lista 11 (Lista Circular Simplesmente Encadeada) --\n\n");
        printf("1. Exercicio 1: Frequencia de um numero na lista 1\n");
        printf("2. Exercicio 3: Excluir todos os nos da lista 1\n");
        printf("3. Exercicio 5: Remover elemento da lista 1 (ordenada)\n");
        printf("4. Exercicio 7: Verificar se listas 1 e 2 sao iguais\n");
        printf("5. Exercicio 9: Copiar lista 1 para lista 2 (sem repetidos)\n");
        printf("6. Inserir ordenado na lista 1\n");
        printf("7. Inserir no inicio da lista 1\n");
        printf("8. Inserir no inicio da lista 2\n");
        printf("--> ");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o numero para verificar a frequencia na lista 1: ");
                scanf("%d", &value);
                printf("O numero %d aparece %d vezes na lista 1\n", value, freq_num(lista1, value));
                break;
            case 2:
                excluir_nodes(&lista1);
                printf("Todos os nos da lista 1 foram excluidos.\n");
                break;
            case 3:
                printf("Digite o valor deseja remover da lista 1: ");
                scanf("%d", &value);
                remover_lista_ordenada(&lista1, value);
                break;
            case 4:
                if (listas_iguais(lista1, lista2)) {
                    printf("As listas 1 e 2 sao iguais.\n");
                } else {
                    printf("As listas 1 e 2 sao diferentes.\n");
                }
                break;
            case 5:
                copia_lista_circular(lista1, &lista2);
                printf("Lista 1 copiada para lista 2 (sem repetidos).\n");
                break;
            case 6:
                printf("Digite o valor para inserir ordenado na lista 1: ");
                scanf("%d", &value);
                inserir_ordenado(&lista1, value);
                break;
            case 7:
                printf("Digite o valor para inserir no inicio da lista 1: ");
                scanf("%d", &value);
                inserir_inicio(&lista1, value);
                break;
             case 8:
                printf("Digite o valor para inserir no inicio da lista 2: ");
                scanf("%d", &value);
                inserir_inicio(&lista2, value);
                break;
            default:
                printf("Escolha invalida!\n");
        }

        printf("\nLista 1: ");
        mostrar_lista(lista1);
        printf("\nLista 2: ");
        mostrar_lista(lista2);
        printf("\n\n");

        printf("Executar o programa novamente? (S - SIM | N - NAO): ");
        scanf(" %c", &continuar);
    }
    while(toupper(continuar) == 'S');

    return 0;
}