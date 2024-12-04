//Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 300000; //tamanho do vetor

void insertionSort(int v[TAM]) {
    int i, j, key;
    for (i = 1; i < TAM; i++) {
        key = v[i];
        j = i - 1;

        // Move elementos do vetor que são maiores que a chave
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

int main(){
    clock_t t; //variável para armazenar tempo
    int vetor[TAM];
    
    //semente de aleatoriedade
    srand((unsigned)time(NULL));

    //geração aleatório dos valores do vetor
    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    //Verificando tempo de execução do bubble sort=> t2
    t = clock(); //armazena tempo
    insertionSort(vetor);
    t = clock() - t; //tempo final - tempo 

    //imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double

    return 0;
}
