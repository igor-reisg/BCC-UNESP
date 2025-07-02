#include <stdio.h>
#include <stdlib.h>

typedef struct reg *node;

struct reg {
    int val;
    node next;
};

int funcaoHash(int value, int TAM) {
    return value % TAM;
}

void inserirFinal(node *lista, int value) {
    node p = (node)malloc(sizeof(struct reg));
    p->val = value;
    p->next = NULL;

    if (*lista == NULL) {
        *lista = p;
    }
    else {
        node q = *lista;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void inicializarTabela(node tabela[], int TAM) {
    for (int i = 0; i < TAM; i++) {
        tabela[i] = NULL;
    }
}

void limparTabela(node tabela[], int TAM) {
    for (int i = 0; i < TAM; i++) {
        node p = tabela[i];
        while (p != NULL) {
            node q = p;
            p = p->next;
            free(q);
        }
        tabela[i] = NULL;
    }
}

int main() {
    int t, tam, itens, index, value;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &tam, &itens);

        node tabela[tam];

        inicializarTabela(tabela, tam);

        for (int i = 0; i < itens; i++) {
            scanf("%d", &value);
            index = funcaoHash(value, tam);
            inserirFinal(&tabela[index], value);
        }

        for (int i = 0; i < tam; i++) {
            node p = tabela[i];
            printf("%d ->", i);

            while(p != NULL) {
                printf(" %d ->", p->val);
                p = p->next;
            }
            printf(" \\\n");
        }

        limparTabela(tabela, tam);

        if (t >= 1) {
            printf("\n");
        }
    }
}