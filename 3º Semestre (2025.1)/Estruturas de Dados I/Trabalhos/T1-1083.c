#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 500

typedef struct reg *node;

struct reg {
    char val;
    node next;
};

void inicializar_pilha(node *pilha) {
    *pilha = NULL;
}

int pilha_vazia(node pilha) {
    return (pilha == NULL);
}

void push(node *pilha, char value) {
    node p = (node)malloc(sizeof(struct reg));
    p->val = value;
    p->next = *pilha;
    *pilha = p;
}

int pop(node *pilha) {
    if (pilha_vazia(*pilha)) return 0;

    node p = *pilha;
    *pilha = (*pilha)->next;
    free(p);
    return 1;
}

char topo(node pilha) {
    if (pilha_vazia(pilha)) return '\0';
    return pilha->val;
}

int precedencia(char op) {
    switch(op) {
        case '^': return 6;
        case '*': 
        case '/': return 5;
        case '+': 
        case '-': return 4;
        case '>':
        case '<':
        case '=':
        case '#': return 3;
        case '.': return 2;
        case '|': return 1;
        default: 
            return 0;
    }
}

int ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '.' || c == '|' || c == '>' || c == '<' || c == '=' || c == '#');
}

void infixaParaPosfixa(char *infixa, char *posfixa) {
    node stack;
    int j = 0;

    inicializar_pilha(&stack);
    
    for (int i = 0; infixa[i] != '\0'; i++) {
        char c = infixa[i];

        if (isalnum(c)) {
            posfixa[j++] = c;
        }
        else if (c == '(') {
            push(&stack, c);
        }
        else if (c == ')') {
            while (!pilha_vazia(stack) && topo(stack) != '(') {
                posfixa[j++] = topo(stack);
                pop(&stack);
            }
            if (!pilha_vazia(stack) && topo(stack) == '(')
                pop(&stack);
        }
        else if (ehOperador(c)) {
            while (!pilha_vazia(stack) && precedencia(topo(stack)) >= precedencia(c)) {
                posfixa[j++] = topo(stack);
                pop(&stack);
            }
            push(&stack, c);
        }
    }

    while (!pilha_vazia(stack)) {
        posfixa[j++] = topo(stack);
        pop(&stack);
    }

    posfixa[j] = '\0';
}

int lexicaCorreta(char *infixa) {
    for (int i = 0; infixa[i] != '\0'; i++) {
        char c = infixa[i];

        if(!isalnum(c) && c != ')' && c != '(' && !ehOperador(c))
            return 0;
    }
    return 1;
}

int sintaxeCorreta(char *infixa) {
    node stack;
    char anterior = 0;

    inicializar_pilha(&stack);

    for (int i = 0; infixa[i] != '\0'; i++) {
        char atual = infixa[i];

        if (atual == '(') {
            push(&stack, '(');

            if(isalnum(anterior)) return 0;
        }
        else if (atual == ')') {
            if(pilha_vazia(stack)) {
                return 0;
            }
            pop(&stack);

            if (ehOperador(anterior)) return 0;
        }
        else if (ehOperador(atual)) {
            if (i == 0) return 0;

            if (ehOperador(anterior) || anterior == '(') return 0;
        }
        else if (isalnum(atual)) {
            if(isalnum(anterior)) return 0;
        }
        anterior = atual;
    }

    if(ehOperador(anterior)) return 0;

    if (!pilha_vazia(stack)) return 0;

    return 1;
}

int main() {
    char infixa[MAX], posfixa[MAX];

    while (scanf("%s", infixa) != EOF) {
        infixa[strcspn(infixa, "\n")] = '\0';

        int resultadoLexica = lexicaCorreta(infixa);
        int resultadoSintaxe = sintaxeCorreta(infixa);

        if (!resultadoLexica) {
            printf("Lexical Error!\n");
            continue;
        }

        if (!resultadoSintaxe) {
            printf("Syntax Error!\n");
            continue;
        }

        infixaParaPosfixa(infixa, posfixa);
        printf("%s\n", posfixa);
    }
}
