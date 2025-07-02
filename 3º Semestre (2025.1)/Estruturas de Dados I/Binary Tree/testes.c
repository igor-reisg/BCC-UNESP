#include <stdio.h>
#include <stdlib.h>

typedef struct reg *node;
typedef struct reg2 *node2;

struct reg {
    int val;
    node esq, dir;
};

struct reg2 {
    node arvore;
    node2 next;
};

void inicializa_fila(node2 *fila) {
    *fila = NULL;
}

int fila_vazia(node2 fila) {
    return (fila == NULL);
}

void enqueue(node2 *fila, node arvore) {
    node2 p = (node2)malloc(sizeof(struct reg2));
    p->arvore = arvore;
    p->next = NULL;

    if(fila_vazia(*fila)) {
        *fila = p;
    }
    else {
        node2 q = *fila;
        while(q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

node dequeue(node2 *fila) {
    if(fila_vazia(*fila)) return NULL;

    node2 p = *fila;
    *fila = (*fila)->next;
    node tree = p->arvore;
    free(p);
    return tree;
}

void inicializa_arvore(node *arvore) {
    *arvore = NULL;
}

int arvore_vazia(node arvore) {
    return (arvore == NULL);
}

void inserir_arvore(node *arvore, int valor) {
    if(arvore_vazia(*arvore)) {
        node p = (node)malloc(sizeof(struct reg));
        p->val = valor;
        p->esq = p->dir = NULL;
        *arvore = p;
    }
    else {
        if (valor < (*arvore)->val) {
            inserir_arvore(&(*arvore)->esq, valor);
        }
        else
            inserir_arvore(&(*arvore)->dir, valor);
    }
}

void limpa_arvore(node *arvore) {
    if (arvore_vazia(*arvore)) return;

    limpa_arvore(&(*arvore)->esq);
    limpa_arvore(&(*arvore)->dir);
    free(*arvore);
}

void preorder(node arvore) {
    if (arvore_vazia(arvore)) {
        return;
    }

    printf(" %d", arvore->val);
    preorder(arvore->esq);
    preorder(arvore->dir);
}

void inorder(node arvore) {
    if (arvore_vazia(arvore)) {
        return;
    }

    inorder(arvore->esq);
    printf(" %d", arvore->val);
    inorder(arvore->dir);
}

void postorder(node arvore) {
    if (arvore_vazia(arvore)) {
        return;
    }

    postorder(arvore->esq);
    postorder(arvore->dir);
    printf(" %d", arvore->val);
}

void perlevel(node arvore) {
    if (arvore_vazia(arvore)) return;

    node2 fila;
    inicializa_fila(&fila);

    enqueue(&fila, arvore);
    while(!fila_vazia(fila)) {
        node tree = dequeue(&fila);

        if (tree->esq) enqueue(&fila, tree->esq);
        if (tree->dir) enqueue(&fila, tree->dir);

        printf(" %d", tree->val);
    }
}

node remover_arvore(node arvore, int value) {
    if (arvore_vazia(arvore)) return NULL;

    if (value < arvore->val) {
        remover_arvore(arvore->esq, value);
    }
    else if (value > arvore->val) {
        remover_arvore(arvore->dir, value);
    }
    else {
        if (arvore->dir == NULL && arvore->esq == NULL) {
            free(arvore);
            return NULL;
        }
        else if (arvore->dir == NULL) {
            node novo = arvore->esq;
            free(arvore);
            return novo;
        }
        else if (arvore->esq == NULL) {
            node novo = arvore->dir;
            free(arvore);
            return novo;
        }
        else {
            node novo = arvore->dir;
            while(novo->esq != NULL) {
                novo = novo->esq;
            }
            arvore->val = novo->val;
            arvore->dir = remover_arvore(arvore->dir, novo->val);
        }
    }
}

int main() {
    int n, valor;
    node arvore;

    printf("Digite quantos itens na arvore: ");
    scanf("%d", &n);

    inicializa_arvore(&arvore);

    while(n--) {
        scanf("%d", &valor);
        inserir_arvore(&arvore, valor);
    }

    printf("Pre.:");
    preorder(arvore);
    printf("\nIn..:");
    inorder(arvore);
    printf("\nPost:");
    postorder(arvore);
    printf("\nLevel:");
    perlevel(arvore);
}