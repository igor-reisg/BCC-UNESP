#include <stdio.h>

int main() {
    
    int N, i, j, count = 0;
    float vet[100], freq[100];
    
    printf("Tamanho da sequencia: ");
    scanf("%d", &N);
    
    for (i = 0; i < N; i++) {
        printf("vet[%d] = ", i);
        scanf("%f", &vet[i]);
        freq[i] = -1;
    }
    
    for (i = 0; i < N; i++) {
        count = 1; 
        for (j = i + 1; j < N; j++) {
            if (vet[i] == vet[j]) {
                count++;
                freq[j] = 0;
            }
        }
            
        if(freq[i] != 0){
            freq[i] = count;
        }
        
    }

    for (i = 0; i < N; i++) {
        if (freq[i] != 0) {
            printf("%.1f ocorre %.0f vezes\n", vet[i], freq[i]);
        }
    }
    return 0;
}
