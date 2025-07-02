#include <stdlib.h>
#include <stdio.h>

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

void inicializa_fila(node1 *fila) {
    *fila = NULL;
}

int fila_vazia(node1 fila) {
    return (fila == NULL);
}

void enqueue(node1 *fila, node arvore) {
    node1 p = (node1)malloc(sizeof(struct reg));
    p->tree = arvore;
    p->next = NULL;
    
    if (fila_vazia(*fila)) {
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
    node arvore = p->tree;
    *fila = (*fila)->next;
    free(p);
    return arvore;
}

void inicializa_arvore(node *arvore) {
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
        else if (value > (*arvore)->val) {
            inserir_arvore(&(*arvore)->dir, value);
        }
    }
}

void preorder(node arvore) {
    if (arvore_vazia(arvore)) return;

    printf(" %d", arvore->val);
    preorder(arvore->esq);
    preorder(arvore->dir);
}

void inorder(node arvore) {
    if(arvore_vazia(arvore)) return;

    inorder(arvore->esq);
    printf(" %d", arvore->val);
    inorder(arvore->dir);
}

void postorder(node arvore) {
    if (arvore_vazia(arvore)) return;

    postorder(arvore->esq);
    postorder(arvore->dir);
    printf(" %d", arvore->val);
}

void inlevel(node arvore) {
    node1 fila;

    inicializa_fila(&fila);

    enqueue(&fila, arvore);
    while(!fila_vazia(fila)) {
        node tree = dequeue(&fila);

        if (tree->esq != NULL) enqueue(&fila, tree->esq);
        if (tree->dir != NULL) enqueue(&fila, tree->dir);

        printf(" %d", tree->val);
    }
}

int main() {
    node arvore;
    int n, valor;

    inicializa_arvore(&arvore);

    printf("Quantidade de elementos na arvore: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);
        inserir_arvore(&arvore, valor);
    }

    printf("\nPreorder.:");
    preorder(arvore);

    printf("\nInorder..:");
    inorder(arvore);

    printf("\nPostorder:");
    postorder(arvore);

    printf("\nInlevel..:");
    inlevel(arvore);
    printf("\n");
}