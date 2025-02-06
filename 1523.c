// Pedro Henrique Novello D'Elia Porto de ALmeida RA: 176620
#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

typedef struct pilha {
    int topo;
    int chegada[MAX];
    int saida[MAX];
} Pilha;

Pilha* cria_pilha();
void liberar_pilha(Pilha* p);
int esta_vazia(Pilha* p);
int esta_cheia(Pilha* p, int vagas);
int push(Pilha* p, int c, int s, int vagas);
int pop(Pilha* p);

int main(){
    int k, n, ci, si;
    int i;
    while(1){
        scanf("%d %d", &n, &k);
        if(k == 0 && n == 0) break;
        Pilha* p = cria_pilha();
        int possivel = 1;
        for(i = 0; i < n; i++){
            scanf("%d %d", &ci, &si);
            if(possivel){
                if(esta_vazia(p)){
                    push(p, ci, si, k);
                    possivel = 1;
                } else {
                    while(ci >= p->saida[p->topo-1]){
                        pop(p);
                        if(esta_vazia(p)) break;
                    }
                    if(esta_cheia(p, k)){
                        possivel = 0;
                    } else {
                        push(p, ci, si, k);
                        if(p->topo > 1){
                            if(p->chegada[p->topo-1] > p->chegada[p->topo -2] && p->saida[p->topo -1] < p->saida[p->topo -2]){
                                possivel = 1;
                            }else{
                                possivel = 0;
                            }
                        } else {
                            possivel = 1;
                        }
                    }
                }
            }
        }
        if(possivel) printf("Sim\n");
        else printf("Nao\n");
        liberar_pilha(p);
    }
}

Pilha* cria_pilha(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

void liberar_pilha(Pilha* p){
    free(p);
}

int esta_vazia(Pilha* p){
    if (p->topo == 0) return 1;
    else return 0;
}

int esta_cheia(Pilha* p, int vagas){
    if (p->topo == vagas) return 1;
    else return 0;
}

int push(Pilha* p, int c, int s, int vagas){
    if (!esta_cheia(p, vagas)){
        p->chegada[p->topo] = c;
        p->saida[p->topo] = s;
        p->topo++;
        return 1;
    } else {
        return 0;
    }
}

int pop(Pilha* p){
    if(!esta_vazia(p)){
        p->topo--;
        return 1;
    } else {
        return 0;
    }
}
