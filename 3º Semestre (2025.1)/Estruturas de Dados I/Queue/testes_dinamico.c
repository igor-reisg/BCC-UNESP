#include <stdlib.h>
#include <stdio.h>

typedef struct reg *node;

struct reg {
    int val;
    node next;
};

void inicializa_fila(node *fila) {
    *fila = NULL;
}

int fila_vazia(node fila) {
    return (fila == NULL);
}

void enqueue(node *fila, int value) {
    node p = (node)malloc(sizeof(struct reg));

    p->val = value;
    p->next = NULL;

    if (fila_vazia(*fila)) {
        *fila = p;
    }
    else {
        node q = *fila;
        while(q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void dequeue(node *fila) {
    if(fila_vazia(*fila)) return;

    node p = *fila;
    *fila = (*fila)->next;
    free(p); 
}

int main() {
    node fila;

    inicializa_fila(&fila);

    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);

    printf("Primeiro da fila: %d\n", fila->val);

    dequeue(&fila);

    printf("Primeiro da fila (pos dequeue): %d\n", fila->val);

}