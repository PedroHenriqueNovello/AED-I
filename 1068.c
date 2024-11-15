//Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pilha1{
    char val;
    struct Pilha1 *abaixo
};

struct pilha{
    int tam;
    struct Pilha1 *acima;
};

void push(struct pilha *p, int val){
    p->tam += 1;

    struct Pilha1 *acima_novo = (struct Pilha1 *)malloc(sizeof(struct Pilha1));

    acima_novo->val = val;
    acima_novo->abaixo = p->acima;
    p->acima = acima_novo;
}

void pop(struct pilha *p){
    if (p->tam > 0)
    {
        p->tam -= 1;
        struct Pilha1 *acima_antes = p->acima;
        p->acima = p->acima->abaixo;
        free(acima_antes);
    }
}

char top(struct pilha *p){
    return p->acima->val;
}

int size(struct pilha *p){
    return p->tam;
}

int empty(struct pilha *p){
    return p->tam == 0;
}

void inicia(struct pilha *p){
    p->tam = 0;
    p->acima = NULL;
}

void apaga(struct pilha *p){
    while (!empty(p))
    {
        pop(p);
    }
}

int main(){
    int i, t;
    struct pilha p;
    char conta[1001];

    while(scanf("%s\n", &conta) != EOF){
        inicia(&p);
        t = strlen(conta);

        for(i = 0; i < t; i++){
            if(conta[i] == '('){
                push(&p, '(');
               }
            else if (conta[i] == ')'){
                if (empty(&p))
                    break;
                else
                    pop(&p);
            }
        }

        if (i == t && empty(&p))
            printf("correct\n");
        else
            printf("incorrect\n");

        apaga(&p);
    }


}
