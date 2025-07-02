#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct reg *node;

struct reg {
    char val[10];
    node next;
};

void inicializar_fila(node *fila) {
    *fila = NULL;
}

int fila_vazia(node fila) {
    return (fila == NULL);
}

void enqueue(node *fila, char *value) {
    node p = (node)malloc(sizeof(struct reg));
    strcpy(p->val, value);
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

char *dequeue(node *fila) {
    if (fila_vazia(*fila)) return NULL;

    node p = *fila;
    *fila = (*fila)->next;
    return p->val;
}

int main() {
    int p;
    char val[10];
    node fn, fs, fl, fo;

    inicializar_fila(&fn);
    inicializar_fila(&fs);
    inicializar_fila(&fl);
    inicializar_fila(&fo);

    while(1) {
        scanf("%d", &p);
        if (p == 0) break;

        scanf("%s", val);

        if (p == -4) enqueue(&fl, val);
        else if (p == -3) enqueue(&fn, val);
        else if (p == -2) enqueue(&fs, val);
        else if (p == -1) enqueue(&fo, val);
    }

    while(!fila_vazia(fn) || !fila_vazia(fs) || !fila_vazia(fl) || !fila_vazia(fo)) {
        char *res = NULL;

        if (!fila_vazia(fo)) {
            res = dequeue(&fo);
            printf("%s ", res);
            free(res);
        }
        
        if (!fila_vazia(fn)) {
            res = dequeue(&fn);
            printf("%s ", res);
            free(res);
        }

        if (!fila_vazia(fs)) {
            res = dequeue(&fs);
            printf("%s ", res);
            free(res);
        }

        if (!fila_vazia(fl)) {
            res = dequeue(&fl);
            printf("%s ", res);
            free(res);
        }
    }
    printf("\n");
}