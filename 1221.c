// Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620
#include <stdio.h>
#include <math.h>

// Função para verificar se um número é primo
int eh_primo(unsigned int numero) {
    if (numero < 2) return 0;
    if (numero == 2 || numero == 3) return 1;
    if (numero % 2 == 0) return 0;
    
    unsigned int limite = sqrt(numero);
    for (unsigned int i = 3; i <= limite; i += 2) {
        if (numero % i == 0) return 0;
    }
    return 1;
}

int main() {
    int quantidade_testes;
    scanf("%d", &quantidade_testes);
    
    while (quantidade_testes--) {
        unsigned int numero;
        scanf("%u", &numero);
        
        if (eh_primo(numero))
            printf("Prime\n");
        else
            printf("Not Prime\n");
    }
    
    return 0;
}
