//Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620
#include <stdio.h>
#include <math.h>
int main(){
    int A, B, C, maiorAB, maiorAC, maiorBC;
    scanf("%d %d %d", &A, &B, &C);
    maiorAB = (A+B+abs(A-B))/2;
    maiorAC = (A+C+abs(A-C))/2;
    maiorBC = (B+C+abs(B-C))/2;
    //analisando dois a dois 
    if (maiorAB == maiorAC){
        printf("%d eh o maior\n", A);
    }
    else if (maiorAB == maiorBC){
        printf("%d eh o maior\n", B);
    }
    else if (maiorAC == maiorBC){
        printf("%d eh o maior\n", C);
    }
    return 0;

}
