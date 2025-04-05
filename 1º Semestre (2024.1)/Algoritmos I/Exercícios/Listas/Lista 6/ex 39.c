#include <stdio.h>
#include <conio.h>
#include <locale.h>

#define esc 27

int main(){
  
  setlocale(LC_ALL,"Portuguese");
  
  char caracter;
  do {
    caracter = getch();

    if (caracter <= 0){
	    caracter = getch();
      printf ("Tecla especial: #0 #%d\n", caracter);
    }
    else 
      printf("Caracter: %c Tecla: #%d\n", caracter, caracter);

  } while (caracter != esc);    
}