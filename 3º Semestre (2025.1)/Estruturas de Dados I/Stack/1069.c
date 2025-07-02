#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 1000

typedef struct reg *node;

struct reg {
    char val;
    node next;
};

void inicializa_pilha(node *p) {
    *p = NULL;
}

int pilha_vazia(node p) {
    return (p == NULL);
}

void push(node *pilha, char value) {
    node p = (node)malloc(sizeof(struct reg));

    p->val = value;
    p->next = *pilha;
    *pilha = p;
}

int pop(node *pilha) {
    if (pilha_vazia(*pilha)) return 0;

    node p = *pilha;
    *pilha = (*pilha)->next;
    free(p);
    return 1;
}

int main() {
    int n, diamantes;
    node p;
    char expressao[max];

    scanf("%d", &n);
    getchar();

    while(n--) {
        diamantes = 0;
        fgets(expressao, max, stdin);
        expressao[strcspn(expressao, "\n")] = '\0';
        
        inicializa_pilha(&p);
        for (int i = 0; expressao[i] != '\0'; i++) {
            if(expressao[i] == '<') {
                push(&p, '<');
            }
            else if(expressao[i] == '>') {
                if(pop(&p)) diamantes++;
            }
        }
        printf("%d\n", diamantes);
    }
}