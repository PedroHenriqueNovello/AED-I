//Pedro Henrique Novello D'Elia Porto de ALmeida RA: 176620
#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main(){
    double A, B, C, triangulo, circulo, trapezio, quadrado, retangulo;
    scanf("%lf %lf %lf", &A, &B, &C);
    triangulo = (A * C) / 2;
    circulo = PI * pow(C, 2);
    trapezio = ((A+B) * C)/2;
    quadrado = pow(B,2);
    retangulo = A * B;
    printf("TRIANGULO: %.3lf\nCIRCULO: %.3lf\nTRAPEZIO: %.3lf\nQUADRADO: %.3lf\nRETANGULO: %.3lf\n", triangulo, circulo, trapezio, quadrado, retangulo);
    return 0; 
}
