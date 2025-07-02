#include <stdio.h>
#include <stdlib.h>

typedef struct reg *node;
typedef struct reg1 *node1;

struct reg {
    int val;
    node esq, dir;
};

struct reg1 {
    node tree;
    node1 next;
};

int min(int x, int y) {
    return x < y ? x : y;
}

void inicializar_arvore(node *arvore) {
    *arvore = NULL;
}

int arvore_vazia(node arvore) {
    return (arvore == NULL);
}

void inserir_arvore(node *arvore, int value) {
    if (arvore_vazia(*arvore)) {
        node p = (node)malloc(sizeof(struct reg));
        p->val = value;
        p->esq = p->dir = NULL;
        *arvore = p;
    }
    else {
        if (value < (*arvore)->val) {
            inserir_arvore(&(*arvore)->esq, value);
        }
        else
            inserir_arvore(&(*arvore)->dir, value);
    }
}

void inicializar_fila(node1 *fila) {
    *fila = NULL;
}

int fila_vazia(node1 fila) {
    return (fila == NULL);
}

void enqueue(node1 *fila, node arvore) {
    node1 p = (node1)malloc(sizeof(struct reg1));
    p->tree = arvore;
    p->next = NULL;

    if(fila_vazia(*fila)) {
        *fila = p;
    }
    else {
        node1 q = *fila;
        while(q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

node dequeue(node1 *fila) {
    if (fila_vazia(*fila)) return NULL;

    node1 p = *fila;
    *fila = (*fila)->next;
    node arvore = p->tree;
    free(p);
    return arvore;
}

void verifica_nivel(node arvore) {
    if(arvore_vazia(arvore)) return;

    node1 fila;

    inicializar_fila(&fila);
    enqueue(&fila, arvore);

    int nivel = 0;
    while(!fila_vazia(fila)) {
        int qtd = 0, alt_min = 301;

        node1 p = fila;
        while(p != NULL) {
            qtd++;
            p = p->next;
        }

        for (int i = 0; i < qtd; i++) {
            node arv = dequeue(&fila);
            if(arv) {
                alt_min = min(alt_min, arv->val);

                if (arv->esq) enqueue(&fila, arv->esq);
                if (arv->dir) enqueue (&fila, arv->dir);
            }
        }

        printf("%d %d\n", nivel, alt_min);
        nivel++;
    }
}

int main() {
    int n, alt;
    node arvore;

    inicializar_arvore(&arvore);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &alt);
        inserir_arvore(&arvore, alt);
    }

    verifica_nivel(arvore);
}