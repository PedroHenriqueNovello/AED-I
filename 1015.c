//Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620
#include <stdio.h>
#include <math.h>
int main(){
    float x1, y1, x2, y2, dist;
    scanf("%f %f\n%f %f", &x1, &y1, &x2, &y2);
    dist = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    printf("%.4f\n", dist);
    return 0;

}
