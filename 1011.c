//Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620
#include <stdio.h>
#include <math.h>
#define PI 3.14159
int main(){
    double raio, volume;
    scanf("%lf\n", &raio);
    volume = (4.0/3) * PI * pow(raio, 3);
    printf("VOLUME = %.3lf\n", volume);

    return 0;


}
