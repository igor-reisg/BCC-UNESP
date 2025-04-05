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
        "1. Opcao 1",
        "2. Opcao 2",
        "3. Opcao 3",
        "4. Opcao 4",
        "5. Opcao 5",
    };

    system("cls");

    for (i = 0; i < 9; i++) {
        if (i == opcao - 1) {
            textoMenu(vet[i], 4);
        } else {
            textoMenu(vet[i], 15);
        }
    }
}

int main() {
    int opcao = 1;
    char tecla;

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
            } 
            else if (tecla == SETABAIXO) {
                if (opcao != 9) {
                    opcao++;
                } 
                else {
                    opcao = 1;
                }
            }
        } 
    } while (tecla != ESC);
    
    return 0;
}
