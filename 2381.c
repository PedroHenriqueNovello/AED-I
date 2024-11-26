//Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparacao(const void* a, const void* b){
    return strcmp((char*)a, (char*)b);
}

int main(void){
    int posicao, N;
    char alunos[200][50];

    scanf("%d %d\n", &N, &posicao);

    for(int i = 0; i < N; i++){
        scanf("%s", &alunos[i]);
    }

    qsort(alunos, N, sizeof(char)*50, comparacao);
    printf("%s\n", &alunos[posicao - 1]);

    return 0;
}

