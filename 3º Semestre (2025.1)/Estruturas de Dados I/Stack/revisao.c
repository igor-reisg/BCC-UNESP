#include <stdio.h>
#include <stdlib.h>

typedef struct reg *node;

struct reg {
    int val;
    node next;
};

void inicializar_pilha(node *pilha) {
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

int topo(node pilha) {
    return pilha->val;
}

int main() {
    node pilha;

    inicializar_pilha(&pilha);

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);

    printf("Topo da pilha: %d\n", topo(pilha));

    pop(&pilha);

    printf("Topo da pilha (pos pop): %d\n", topo(pilha));
}