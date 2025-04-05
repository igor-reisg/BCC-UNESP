#include <stdio.h>

#define ESTADOS 26  
#define MUNICIPIOS 10 

int encontrarMaximo(int vetor[], int tamanho) {
    int max = 0, i;
    
    for (i = 1; i < tamanho; i++) {
        if (vetor[i] > vetor[max]) {
        max = i;
        }
    }
    return max;
}

int main() {
    
    int populacao[ESTADOS][MUNICIPIOS], i, j, estadoMunicipioPopuloso = 0;
    int municipioPopuloso = 0, populoso = 0, somaPopCapital = 0;
    float mediaPopCapital;

    for (i = 0; i < ESTADOS; i++) {
        for (j = 0; j < MUNICIPIOS; j++) {
        printf("Digite a populacao do municipio %d do estado %d: ", j + 1, i + 1);
        scanf("%d", &populacao[i][j]);
        }
    }

    for (i = 0; i < ESTADOS; i++) {
        for (j = 0; j < MUNICIPIOS; j++) {
        
            if (populacao[i][j] > populoso) {
                
                estadoMunicipioPopuloso = i;
                municipioPopuloso = j;
                populoso = populacao[i][j];
            }
        }
    }

    for (i = 0; i < ESTADOS; i++) {
        somaPopCapital += populacao[i][0];
    }
    
    mediaPopCapital = (float)somaPopCapital / ESTADOS;

    printf("\nO municipio mais populoso eh o %do do estado %d, com populacao de %d habitantes\n",
            municipioPopuloso + 1, estadoMunicipioPopuloso + 1, populoso);
    printf("A media da populacao das capitais eh de %.2f habitantes\n", mediaPopCapital);

    return 0;
}
