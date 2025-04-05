//TRABALHO 2 - ALGORITMOS I
//IGOR DOS REIS GOMES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define MAX 100
#define SETABAIXO 80
#define SETACIMA 72
#define ESC 27
#define ENTER 13
#define F1 59

void lerMat(int mat[][MAX], int n) {
    int i, j;

    printf("Digite os elementos da matriz: \n");
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("vet[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void mostraMat(int mat[][MAX], int n) {
    int i, j;

    printf("Matriz atual: \n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void trocaLin(int mat[][MAX], int n, int a, int b) {
    int i, temp;
    
    for (i = 0; i < n; i++) {
        temp = mat[a][i];
        mat[a][i] = mat[b][i];
        mat[b][i] = temp;
    }
}

void trocaCol(int mat[][MAX], int n, int a, int b) {
    int i, temp;
    
    for (i = 0; i < n; i++) {
        temp = mat[i][a];
        mat[i][a] = mat[i][b];
        mat[i][b] = temp;
    }
}

void trocaDiag(int mat[][MAX], int n) {
    int i, temp;
    
    for (i = 0; i < n; i++) {
        temp = mat[i][i];
        mat[i][i] = mat[i][n - i - 1];
        mat[i][n - i - 1] = temp;
    }
}

int simetria(int mat[][MAX], int n) {
    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            
            if (mat[i][j] != mat[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int quadMag(int mat[][MAX], int n) {
    int i, j, somadiag = 0, soma = 0;
    
    for (i = 0; i < n; i++) {
        somadiag += mat[i][i];
    }
    for (i = 0; i < n; i++) {
        soma = 0;
        for (j = 0; j < n; j++) {
            soma += mat[i][j];
        }
        if (soma != somadiag) {
            return 0;
        }
    }
    for (j = 0; j < n; j++) {
        soma = 0;
        for (i = 0; i < n; i++) {
            soma += mat[i][j];
        }
        if (soma != somadiag) {
            return 0;
        }
    }
    return 1;
}

int quadLat(int mat[][MAX], int n) {
    int i, j;
    
    for (i = 0; i < n; i++) {
        int lin[100] = {0}, col[100] = {0};
        
        for (j = 0; j < n; j++) {
            if (lin[mat[i][j]] || col[mat[j][i]]) {
                return 0;
            }
            lin[mat[i][j]] = 1;
            col[mat[j][i]] = 1;
        }
    }
    return 1;
}

int matPerm(int mat[][MAX], int n) {
    int i, j;
    
    for (i = 0; i < n; i++) {
        int somalin = 0, somacol = 0;
        for (j = 0; j < n; j++) {
            somalin += mat[i][j];
            somacol += mat[j][i];
        }
        if (somalin != 1 || somacol != 1) {
            return 0;
        }
    }
    return 1;
}

int SetColor(char color) {
    HANDLE a;
    a = GetStdHandle(STD_OUTPUT_HANDLE);

    return SetConsoleTextAttribute(a, color);
}

void textoMenu(char string[], int cor) {
    SetColor(cor);
    printf("%s\n", string);
}

void menu(int opcao) {
    
    int i;
    char *vet[] = {
        "1. Ler matriz",
        "2. Mostrar matriz",
        "3. Trocar linhas",
        "4. Trocar colunas",
        "5. Trocar diagonais",
        "6. Verificar simetria",
        "7. Verificar quadrado magico",
        "8. Verificar quadrado latino",
        "9. Verificar matriz de permutacao"
    };

    system("cls");
    textoMenu("\n=== PROGRAMA DE MANIPULACAO DE MATRIZ ===\n", 15);

    for (i = 0; i < 9; i++) {
        if (i == opcao - 1) {
            textoMenu(vet[i], 4);
        } else {
            textoMenu(vet[i], 15);
        }
    }
    textoMenu("(F1 - AJUDA | ESC - SAIR)\n", 15);
}

int main() {
    int mat[100][100], n, opcao = 1, a, b;
    char tecla;
    
    printf("Digite a dimensao da matriz: ");
    scanf("%d", &n);

    do {
        menu(opcao);
        tecla = getch();

        if (tecla <= 0) {
            tecla = getch();
            
            if (tecla == SETACIMA) {
                if (opcao != 1) {
                    opcao--;
                } 
                else {
                    opcao = 9;
                }
            } else if (tecla == SETABAIXO) {
                if (opcao != 9) {
                    opcao++;
                } 
                else {
                    opcao = 1;
                }
            } else if (tecla == F1) {
                printf("Para o funcionamento correto do programa, é necessário primeiro ler a matriz, para assim realizar as outras opções de forma correta\n");
            }
        } 
        else if (tecla == ENTER) {
            switch (opcao) {
                case 1:
                    lerMat(mat, n);
                    printf("\nPressione ENTER para voltar ao menu...");
                    while (getch() != ENTER); 
                    break;
                case 2:
                    mostraMat(mat, n);
                    printf("\nPressione ENTER para voltar ao menu...");
                    while (getch() != ENTER); 
                    break;
                case 3:
                    printf("Digite quais linhas deseja trocar (a e b): ");
                    scanf("%d %d", &a, &b);
                    trocaLin(mat, n, a, b);
                    printf("\nPressione ENTER para voltar ao menu...");
                    while (getch() != ENTER); 
                    break;
                case 4:
                    printf("Digite quais colunas deseja trocar (a e b): ");
                    scanf("%d %d", &a, &b);
                    trocaCol(mat, n, a, b);
                    printf("\nPressione ENTER para voltar ao menu...");
                    while (getch() != ENTER); 
                    break;
                case 5:
                    trocaDiag(mat, n);
                    printf("\nPressione ENTER para voltar ao menu...");
                    while (getch() != ENTER); 
                    break;
                case 6:
                    if (simetria(mat, n)) {
                        printf("A matriz eh simetrica\n");
                    } 
                    else {
                        printf("A matriz nao eh simetrica\n");
                    }
                    printf("\nPressione ENTER para voltar ao menu...");
                    while (getch() != ENTER); 
                case 7:
                    if (quadMag(mat, n)) {
                        printf("A matriz eh um quadrado magico\n");
                    } 
                    else {
                        printf("A matriz nao eh um quadrado magico\n");
                    }
                    printf("\nPressione ENTER para voltar ao menu...");
                    while (getch() != ENTER); 
                    break;
                case 8:
                    if (quadLat(mat, n)) {
                        printf("A matriz eh um quadrado latino\n");
                    } 
                    else {
                        printf("A matriz nao eh um quadrado latino\n");
                    }
                    printf("\nPressione ENTER para voltar ao menu...");
                    while (getch() != ENTER); 
                    break;
                case 9:
                    if (matPerm(mat, n)) {
                        printf("A matriz eh uma matriz de permutacao\n");
                    } 
                    else {
                        printf("A matriz nao eh uma matriz de permutacao\n");
                    }
                    printf("\nPressione ENTER para voltar ao menu...");
                    while (getch() != ENTER); 
                    break;
                }
        }
    } while (tecla != ESC);
    
    return 0;
}
