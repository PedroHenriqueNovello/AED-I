//Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620
#include <stdio.h>
#include <stdlib.h>  // Para usar a função llabs()

int main() {
    unsigned long long hashmat, oponente;

    // Lê até o final do arquivo (EOF)
    while (scanf("%llu %llu", &hashmat, &oponente) == 2) {
        printf("%llu\n", llabs(hashmat - oponente));
    }

    return 0;
}
