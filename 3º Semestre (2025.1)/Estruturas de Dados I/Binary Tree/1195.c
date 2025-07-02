#include <stdio.h>
#include <stdlib.h>

typedef struct reg *node;

struct reg {
    int val;
    node esq, dir;
};

void inicializa_arvore(node *arvore) {
    *arvore = NULL;
}

int arvore_vazia(node arvore) {
    return (arvore == NULL);
}

void limpar_arvore(node *arvore) {
    if (arvore_vazia(*arvore)) return;

    limpar_arvore(&(*arvore)->esq);
    limpar_arvore(&(*arvore)->dir);
    free(*arvore);
}

void inserir_arvore(node *arvore, int valor) {
    if (arvore_vazia(*arvore)) {
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

int main() {
    int c, n, val;
    node arvore;

    scanf("%d", &c);

    for(int i = 0; i < c; i++) {
        inicializa_arvore(&arvore);
    
        scanf("%d", &n);
        while(n--) {
            scanf("%d", &val);
            inserir_arvore(&arvore, val);
        }

        printf("Case %d:\n", i + 1);
        printf("Pre.:");
        preorder(arvore);

        printf("\nIn..:");
        inorder(arvore);

        printf("\nPost:");
        postorder(arvore);
        printf("\n\n");

        limpar_arvore(&arvore);
    }
}