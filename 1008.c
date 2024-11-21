//Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620
#include <stdio.h>
 
int main() {
    int horas_trab, numero_funcionario;
    double salary, valor_hora;
    scanf ("%i %i %lf", &numero_funcionario, &horas_trab, &valor_hora);
    salary = horas_trab * valor_hora;
    printf("NUMBER = %i\nSALARY = U$ %.2f\n", numero_funcionario, salary);
 
    return 0;
}
