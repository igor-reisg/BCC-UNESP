#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char descricao[100];
    int qtd;
    float preco;
} lista;

void inserir_produto(lista compras[], int *qtd) {
    lista novoprod;

    printf("Digite o codigo do produto: ");
    scanf("%d", &novoprod.codigo);
    printf("Digite a descricao do produto: ");
    scanf(" %s", novoprod.descricao); 
    printf("Digite a quantidade: ");
    scanf("%d", &novoprod.qtd);
    printf("Digite o preco: R$");
    scanf("%f", &novoprod.preco);

    int pos;
    for (pos = 0; pos < *qtd; pos++) {
        if (compras[pos].codigo > novoprod.codigo) {
            break; 
        }
    }

    for (int i = *qtd; i > pos; i--) {
        compras[i] = compras[i - 1];
    }

    compras[pos] = novoprod;
    (*qtd)++;
}

void excluir_produto(lista compras[], int *qtd) {
    int codexc, achou = 0;

    printf("Qual produto deseja excluir? (Digite o codigo): ");
    scanf("%d", &codexc);

    for (int i = 0; i < *qtd; i++) {
        if (compras[i].codigo == codexc) {
            achou = 1;
            for (int j = i; j < *qtd - 1; j++) {
                compras[j] = compras[j + 1];
            }
            (*qtd)--;  
            break;     
        }
    }

    if (!achou) {
        printf("Produto com codigo %d nao encontrado.\n", codexc);
    }
}

void consultar_produto(lista compras[], int left, int right) {
    int codbusca, mid;

    printf("Digite o codigo do produto que deseja consultar: ");
    scanf("%d", &codbusca);

    while (left <= right) {
        mid = (left + right) / 2;

        if (compras[mid].codigo == codbusca) {
            printf("PRODUTO %d\n", mid + 1);
            printf("Codigo: %d\n", compras[mid].codigo);
            printf("Descricao: %s\n", compras[mid].descricao);
            printf("Quantidade: %d\n", compras[mid].qtd);
            printf("Preco: R$%.2f\n", compras[mid].preco);
            return; 
        } 
        else if (compras[mid].codigo < codbusca) {
            left = mid + 1;
        } 
        else 
            right = mid - 1;
    }
    
    printf("Produto com codigo %d nao encontrado.\n", codbusca);
}

void mostrar_lista(lista compras[], int *qtd) {
    for (int i = 0; i < *qtd; i++) {
        printf("\nPRODUTO %d\n", i + 1);
        printf("Codigo: %d\n", compras[i].codigo);
        printf("Descricao: %s\n", compras[i].descricao);
        printf("Quantidade: %d\n", compras[i].qtd);
        printf("Preco: R$%.2f\n", compras[i].preco);
    }
}

void ordenar_preco(lista compras[], int *qtd) {
    lista aux;
    int sorted = 0;

    for (int i = 0; i < *qtd && sorted == 0; i++) {
        sorted = 1; 
        for (int j = 0; j < *qtd - 1 - i; j++) {
            if (compras[j].preco > compras[j + 1].preco) {
                aux = compras[j];
                compras[j] = compras[j + 1];
                compras[j + 1] = aux;
                sorted = 0; 
            }
        }
    }

    printf("LISTA ORDENADA POR PRECOS:\n");
    mostrar_lista(compras, qtd);
}

int main() {
    lista compras[100];
    int menu;
    int qtd = 0; 

    do {
        printf("\n\n-- LISTA DE COMPRAS --\n");
        printf("[1] Inserir produto\n");
        printf("[2] Excluir produto\n");
        printf("[3] Consultar produto por codigo\n");
        printf("[4] Ordenar lista pelo preco\n");
        printf("[5] Mostrar lista\n");
        printf("[6] Sair\n");
        printf("--> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                inserir_produto(compras, &qtd);
                break;
            case 2:
                excluir_produto(compras, &qtd);
                break;
            case 3:
                consultar_produto(compras, 0, qtd - 1);
                break;
            case 4:
                ordenar_preco(compras, &qtd);
                break;
            case 5:
                mostrar_lista(compras, &qtd);
                break;
            default:
                return 0;
        }
    } 
    while (menu != 6);
}