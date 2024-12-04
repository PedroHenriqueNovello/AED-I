//Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 350000; // constante para tamanho do vetor

void merge(int v[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = v[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
         }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int v[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);
        merge(v, left, mid, right);
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

    // Verificando tempo de execução do merge sort
    t = clock(); // armazena tempo inicial
    mergeSort(vetor, 0, TAM - 1);
    t = clock() - t; // tempo final - tempo inicial

    // imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000))); // conversão para double

    return 0;
}
