#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char estado[20];
    int idade;
    char genero;
} ficha;

void cadastro_paciente(ficha pacientes[], int *qtd) {
    ficha novopaciente;
    int pos;

    printf("\n\nDigite o nome do paciente: ");
    scanf("%s", novopaciente.nome);

    printf("Digite o estado do paciente: ");
    scanf("%s", novopaciente.estado);

    printf("Digite a idade do paciente: ");
    scanf("%d", &novopaciente.idade);

    getchar();

    printf("Digite o genero do paciente (M - Masculino | F - Feminino): ");
    scanf("%c", &novopaciente.genero);

    for (pos = 0; pos < *qtd; pos++) {
        if ((strcmp(novopaciente.estado, "pessimo") == 0 && strcmp(pacientes[pos].estado, "pessimo") != 0) ||
            (strcmp(novopaciente.estado, "ruim") == 0 && strcmp(pacientes[pos].estado, "regular") == 0)) {
                break;
            }
    }

    for (int i = *qtd; i > pos; i--) {
        pacientes[i] = pacientes[i - 1];
    }

    pacientes[pos] = novopaciente;
    (*qtd)++;
}

void proximo_paciente(ficha pacientes[], int *vez) {
    
    printf("\n\nPACIENTE %d\n", *vez + 1);
    printf("Nome: %s\n", pacientes[*vez].nome);
    printf("Idade: %d\n", pacientes[*vez].idade);
    printf("Genero: %c\n", pacientes[*vez].genero);
    printf("Estado: %s\n", pacientes[*vez].estado);
}

void mostrar_lista(ficha pacientes[], int *qtd) {

    for(int i = 0; i < *qtd; i++) {
        printf("\n\nPACIENTE %d\n", i + 1);
        printf("Nome: %s\n", pacientes[i].nome);
        printf("Idade: %d\n", pacientes[i].idade);
        printf("Genero: %c\n", pacientes[i].genero);
        printf("Estado: %s\n", pacientes[i].estado);
    }
}

int main() {
    int qtd = 0, opcao, vez = 0;
    ficha pacientes[100];

    do {
        printf("-- FICHA DE PACIENTES --\n");
        printf("1. Cadastrar novo paciente\n");
        printf("2. Proximo paciente\n");
        printf("3. Lista de pacientes por estado\n");
        printf("4. Sair\n");
        printf("--> ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastro_paciente(pacientes, &qtd);
                break;
            case 2:
                proximo_paciente(pacientes, &vez);
                vez++;
                break;
            case 3:
                mostrar_lista(pacientes, &qtd);
                break;
            case 4:
                printf("Saindo...");
                break;
        }
    }
    while (opcao != 4);
}