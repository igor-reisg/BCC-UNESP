#include <stdio.h>

int binary_search_recursive(int target, int *vet, int left, int right) {
    int mid = (left + right) / 2;
    
    if (left > right) {  
        return -1;
    }

    if (target == vet[mid]) {
        return mid;
    } 
    else if (target < vet[mid]) {
        return binary_search_recursive(target, vet, left, mid - 1);  
    } 
    else
        return binary_search_recursive(target, vet, mid + 1, right);  
}

int binary_search_iterative(int target, int *vet, int left, int right) {
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (target == vet[mid]) {
            return mid;
        }
        else if (target < vet[mid]) {
            right = mid - 1;
        }
        else if (target > vet[mid]) {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int vet[50], tam, target, left, right;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    for (int i = 0; i < tam; i++) {
        printf("vet[%d] = ", i);
        scanf("%d", &vet[i]);
    }

    printf("Digite o valor buscado no vetor: ");
    scanf("%d", &target);

    left = 0;
    right = tam - 1;

    printf("(Iterativo) O numero '%d' esta presente no index '%d' do vetor\n", target, binary_search_iterative(target, vet, left, right));
    printf("(Recursivo) O numero '%d' esta presente no index '%d' do vetor\n", target, binary_search_recursive(target, vet, left, right));
}