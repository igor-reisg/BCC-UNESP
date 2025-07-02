#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int vet[MAX];
    int top;
} pilha;

void inicializar_pilha(pilha *p) {
    p->top = -1;
}

int verifica_pilha_vazia(pilha p) {
    return (p.top == -1);
}

void pop(pilha *p) {
    if(verifica_pilha_vazia(*p)) {
        printf("Pilha já está vazia.\n");
        return;
    }

    (p->top)--;
}

void push(pilha *p, int val) {
    if (p->top >= MAX - 1) {
        printf("Pilha cheia.\n");
        return;
    }

    p->top++;
    p->vet[p->top] = val;
}

int main() {
    pilha p;

    inicializar_pilha(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    printf("Topo da pilha: %d\n", p.vet[p.top]);

    pop(&p);

    printf("Topo da pilha (pos pop): %d\n", p.vet[p.top]);
}
