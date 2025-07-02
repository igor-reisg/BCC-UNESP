#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct reg *node;

struct reg {
    char *val;
    node esq, dir;
};

void inicializa_arvore(node *arvore) {
    *arvore = NULL;
}

int arvore_vazia(node arvore) {
    return (arvore == NULL);
}

void inserir_arvore(node *arvore, char *palavra) {
    if (arvore_vazia(*arvore)) {
        node p = (node)malloc(sizeof(struct reg));
        p->val = (char *)malloc(strlen(palavra) + 1);
        strcpy(p->val, palavra);
        p->esq = p->dir = NULL;
        *arvore = p;
    } 
    else {
        int comparar = strcmp(palavra, (*arvore)->val);
        if (comparar < 0) {
            inserir_arvore(&(*arvore)->esq, palavra);
        } 
        else if (comparar > 0) {
            inserir_arvore(&(*arvore)->dir, palavra);
        }
    }
}

void inorder(node arvore) {
    if (arvore_vazia(arvore)) return;
    
    inorder(arvore->esq);
    printf("%s\n", arvore->val);
    inorder(arvore->dir);
}

void liberar_arvore(node arvore) {
    if (arvore == NULL) return;

    liberar_arvore(arvore->esq);
    liberar_arvore(arvore->dir);
    free(arvore->val);
    free(arvore);
}

int main() {
    node arvore;
    inicializa_arvore(&arvore);

    char linha[201], palavra[201];
    int i, j;

    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        i = 0;
        while (linha[i]) {
            if (isalpha(linha[i])) {
                j = 0;
                while (isalpha(linha[i])) {
                    palavra[j++] = tolower(linha[i++]);
                }
                palavra[j] = '\0';
                inserir_arvore(&arvore, palavra);
            } 
            else
                i++;
        }
    }

    inorder(arvore);
    liberar_arvore(arvore);
}
