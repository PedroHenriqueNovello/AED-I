// Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620

#include <stdio.h>

int main() {
    int idade, anos, meses, dias;
    
    printf("");
    scanf("%d",&idade);
    
    anos = idade/365;
    meses = (idade%365)/30;
    dias = (idade%365)%30;
    
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", anos, meses, dias);
    return 0;
}
