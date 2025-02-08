//Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620
#include <stdio.h>
#include <math.h>

// Função para retornar o maior entre três valores
int maior_de_tres(int r, int b, int c) {
    if (r >= b && r >= c)
        return r;
    else if (b >= r && b >= c)
        return b;
    else 
        return c;
}

int main() {
    int N, x, y, r, b, c;

    // Número de casos de teste
    scanf("%d", &N);
   
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);

        r = (int)(pow(3 * x, 2) + pow(y, 2));
        b = (int)(2 * pow(x, 2) + pow(5 * y, 2));
        c = (int)(-100 * x + pow(y, 3));

        int maior = maior_de_tres(r, b, c);
        
        if (maior == r)
            printf("Rafael ganhou\n");
        else if (maior == b)
            printf("Beto ganhou\n");
        else
            printf("Carlos ganhou\n");
    }

    return 0;
}
