#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000

typedef struct reg *node;

struct reg {
    char val;
    node next;
};

void inicializa_pilha(node *pilha) {
    *pilha = NULL;
}

int verifica_pilha_vazia(node pilha) {
    return (pilha == NULL);
}

void push(char value, node *pilha) {
    node p = (node)malloc(sizeof(struct reg));
    p->val = value;
    p->next = *pilha;
    *pilha = p;
}

int pop(node *pilha) {
    if (verifica_pilha_vazia(*pilha)) return 0;

    node p = *pilha;
    *pilha = (*pilha)->next;
    free(p);
    return 1;
}

int main() {
    char frase[TAM];
    node p;
    int erro = 0;

    while (fgets(frase, TAM, stdin)) {
        inicializa_pilha(&p);
        
        frase[strcspn(frase, "\n")] = '\0';
        for (int i = 0; frase[i] != '\0'; i++) {
            if(frase[i] == '(') {
                push('(', &p);
            }
            if (frase[i] == ')') {
                if(!pop(&p)) {
                    erro = 1;
                    printf("incorrect\n");
                    break;
                }
            }
        }
        
        if (!erro) (p == NULL) ? printf("correct\n") : printf("incorrect\n");
    }
}