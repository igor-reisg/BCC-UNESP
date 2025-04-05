#include <stdio.h>

int main(){
  
  int i, j, k, mat[6][6];
 
    for (k = 0; k < 3; k++) {
        for (i = k; i <= 6 - k - 1; i++){
            
            mat[k][i] = k + 1;
            mat[6-k-1][i] = k + 1;
            mat[i][k] = k + 1;
            mat[i][6-k-1] = k + 1;
        }
    } 	

    if (6 % 2 == 1) {
        mat[3][3] = 3+1;
    }
        
    printf("\nMATRIZ GERADA: \n");
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;	  
}