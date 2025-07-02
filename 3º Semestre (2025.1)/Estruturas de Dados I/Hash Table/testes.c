#include <stdio.h>
#include <stdlib.h>

typedef struct reg *node;

struct reg  {
    int val;
    node next;
};

int funcaoHash(int buscado, int TAM) {
    return buscado % TAM;
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
        while(q->next != NULL) {
            q = q->next;
        }
        q->next = p;
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

void inicializarTabela(node tabela[], int TAM) {
    for (int i = 0; i < TAM; i++) {
        tabela[i] = NULL;
    }
}

int buscarTabela(node tabela[], int TAM, int buscado) {
    int index = funcaoHash(buscado, TAM);
    node p = tabela[index];

    while(p != NULL) {
        if (p->val == buscado) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int main() {
    int index, chave, qtd, tam, buscado;

    printf("Quantidade de itens na tebela: ");
    scanf("%d", &qtd);

    printf("Digite o tamanho da tabela: ");
    scanf("%d", &tam);

    node tabela[tam];
    inicializarTabela(tabela, tam);

    printf("Digite os valores: ");
    for (int i = 0; i < qtd; i++) {
        scanf("%d", &chave);
        index = funcaoHash(chave, tam);
        inserirFinal(&tabela[index], chave);
    }

    for (int i = 0; i < tam; i++) {
        printf("[%d] ", i);
        node p = tabela[i];
        while (p != NULL) {
            printf("%d -> ", p->val);
            p = p->next;
        }
        printf("NULL\n");
    }

    printf("\nDigite o valor que deseja buscar: ");
    scanf("%d", &buscado);

    if (buscarTabela(tabela, tam, buscado)) {
        printf("Valor %d encontrado na tabela\n", buscado);
    }
    else
        printf("Valor %d nao encontrado na tabela\n", buscado);

}