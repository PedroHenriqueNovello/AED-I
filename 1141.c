// Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_MAX_S 1129
#define TAM_MAX 1000009
#define TAM_MAX_M 10009

int contador_nos = 1;
int indice[TAM_MAX], resultado[TAM_MAX_M], falha[TAM_MAX], fila[TAM_MAX << 2], trie[TAM_MAX][26];

typedef struct {
    char palavra[TAM_MAX_S];
} String;

String palavras[TAM_MAX_M];

int construirAho();
int resolver(char *);
void inserir(int, char *);
int comparar(const void *, const void *);
int maximo(int, int);

int main() {
    int n, resposta;
    while (scanf("%d", &n), n) {
        contador_nos = 1;
        for (size_t i = 0; i < n; ++i) scanf("%s", palavras[i].palavra), resultado[i + 1] = 0;
        qsort(palavras, n, sizeof(String), comparar);
        for (size_t i = 0; i < n; ++i) inserir(i + 1, palavras[i].palavra);
        construirAho();
        resposta = 1, resultado[1] = 1;
        for (size_t i = 1; i < n; ++i) resposta = maximo(resposta, resultado[i + 1] = resolver(palavras[i].palavra));
        printf("%d\n", resposta);
        for (size_t i = 0; i < contador_nos; ++i) memset(trie[i], 0, sizeof(trie[i])), indice[i] = falha[i] = 0;
    }
    return 0;
}

int comparar(const void *a, const void *b) {
    return strlen(((String *)a)->palavra) > strlen(((String *)b)->palavra);
}

void inserir(int idx, char *s) {
    int no = 0;
    for (size_t i = 0; s[i]; ++i) {
        int c = s[i] - 'a';
        if (!trie[no][c]) trie[no][c] = contador_nos++;
        no = trie[no][c];
    }
    indice[no] = idx;
}

int construirAho() {
    int inicio = 0, fim = 0;
    fila[fim++] = 0;
    while (inicio < fim) {
        int atual = fila[inicio++];
        indice[atual] = maximo(indice[atual], indice[falha[atual]]);
        for (size_t i = 0; i < 26; ++i) {
            if (trie[atual][i]) {
                int filho = trie[atual][i];
                fila[fim++] = filho;
                falha[filho] = atual ? trie[falha[atual]][i] : 0;
            } else trie[atual][i] = trie[falha[atual]][i];
        }
    }
}

int resolver(char *s) {
    int no = 0, resposta = 0;
    for (size_t i = 0; s[i]; ++i) {
        no = trie[no][s[i] - 'a'];
        resposta = maximo(resposta, maximo(resultado[indice[no]], resultado[indice[falha[no]]]));
    }
    return resposta + 1;
}

inline int maximo(int a, int b) { return a > b ? a : b; }
