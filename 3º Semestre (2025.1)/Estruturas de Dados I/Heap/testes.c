#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 10

int tam = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void subirHeap(int heap[], int idx) {
    int pai = (idx - 1) / 2;
    if (heap[idx] > heap[pai] && idx > 0) {
        swap(&heap[pai], &heap[idx]);
        subirHeap(heap, pai);
    }
}

void inserirHeap(int heap[], int val) {
    if (tam >= TAM_MAX) return;
    heap[tam] = val;
    subirHeap(heap, tam);
    tam++;
}

void mostrarHeap(int heap[]) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int heap[TAM_MAX];

    inserirHeap(heap, 10);
    inserirHeap(heap, 30);
    inserirHeap(heap, 90);
    inserirHeap(heap, 20);
    inserirHeap(heap, 40);
    inserirHeap(heap, 50);
    inserirHeap(heap, 70);

    mostrarHeap(heap);
}