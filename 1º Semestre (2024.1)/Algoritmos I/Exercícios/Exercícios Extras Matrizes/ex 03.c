#include <stdio.h>
#define max 15

int main(){
  
    int i, j, k, n, mat[max][max], continuar;
  
    do {
        do {
    	    printf ("Digite a ordem da matriz (maximo %d): ",max);
  	        scanf ("%d",&n);
        } 
        while (n < 1 || n > max); 
        
        for (k = 0; k < n/2; k++)
    	    for (i = k; i <= n-k-1; i++){
    		    
                mat[k][i] = k+1;
    		    mat[n-k-1][i] = k+1;
    		    mat[i][k] = k+1;
    		    mat[i][n-k-1] = k+1;
			} 	
		
        if (n%2) {
		    mat[n/2][n/2] = n/2+1;
        }

        printf ("\nMatriz:\n");
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++) {
                
                printf ("%3d",mat[i][j]);
            }
            printf ("\n");
        }

        printf("\n\nDigite 1 para executar novamente o programa... ");
        scanf ("%d",&continuar);
    } 
    while (continuar == 1);	  
}