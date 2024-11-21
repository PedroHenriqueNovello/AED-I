//Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620
#include <stdio.h>
int main(){
    float tempo, velocidade, dist, litros;
    scanf ("%f %f", &tempo, &velocidade);
    dist = velocidade * tempo;
    litros = dist/12;
    printf("%.3f\n", litros);
    return 0;

}
