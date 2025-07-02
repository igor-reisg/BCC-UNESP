#include <stdlib.h>
#include <stdio.h>

typedef struct reg *node;

struct reg {
    int val;
    node next;
};

void inicializa_pilha(node *pilha) {
    *pilha = NULL;
}

int pilha_vazia(node pilha) {
    return (pilha == NULL);
}

void push(node *pilha, int value) {
    node p = (node)malloc(sizeof(struct reg));
    p->val = value;
    p->next = *pilha;
    *pilha = p;
}

void pop(node *pilha) {
    if (pilha_vazia(*pilha)) return;

    node p = *pilha;
    *pilha = (*pilha)->next;
    free(p);
}

int main() {
    node pilha;

    inicializa_pilha(&pilha);

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);

    printf("Topo da pilha: %d\n", pilha->val);

    pop(&pilha);

    printf("Topo da pilha (pos pop): %d\n", pilha->val);
}