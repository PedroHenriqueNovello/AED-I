// Pedro Henrique Novello D'Elia Porto de Almeida  RA: 176620
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 350000; // constante para tamanho do vetor

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partição do vetor para o QuickSort
int partition(int v[], int low, int high) {
    int pivot = v[high]; // Pivô
    int i = low - 1;     // Índice do menor elemento

    for (int j = low; j < high; j++) {
        if (v[j] <= pivot) {
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[high]);
    return i + 1;
}

// Função de QuickSort
void quickSort(int v[], int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);

        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

int main() {
    clock_t t; // variável para armazenar tempo
    int vetor[TAM];

    // semente de aleatoriedade
    srand((unsigned)time(NULL));

    // geração aleatória dos valores do vetor
    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    // Verificando tempo de execução do QuickSort
    t = clock(); // armazena tempo inicial
    quickSort(vetor, 0, TAM - 1);
    t = clock() - t; // tempo final - tempo inicial

    // imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000))); // conversão para double

    return 0;
}
