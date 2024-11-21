//Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620
#include <stdio.h>
 
int main() {
    char nome;
    double salario_fixo, total_vendas, salario_total;
    scanf("%s %lf %lf", &nome, &salario_fixo, &total_vendas);
    salario_total = salario_fixo + (0.15 * total_vendas);
    printf("TOTAL = R$ %.2f\n", salario_total);
    
 
    return 0;
}
