#include <stdio.h>

int matriz [9][9];

//verificação nas colunas
int mesmacoluna (int x){
    int num[10];
    for (int i = 0; i < 10; i++){
        num[i]=0;
    }
    for (int i = 0; i<9; i++){
        if(num[matriz[x][i]]) return 0;
            num[matriz[x][i]] += 1;
        }
        return 1;
}

//verificação nas linhas 
int mesmalinha (int y){
    int num [10];
    for (int i = 0; i<10; i++){
        num[i] = 0;
    }
    for (int i = 0; i < 9; i++){
        if (num[matriz[i][y]]) return 0;
            num [matriz[i][y]] += 1;
        
    }

    return 1;
}

//verificação em cada matriz interna
int mesmamatrizI (int x){
    int num[10];
    int linha = 3*(x/3), coluna = 3*(x%3);

    for (int i = 0; i < 10; i++){
        num [i] = 0;
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (num[matriz[linha + i][coluna +j]]) return 0;
                num[matriz[linha+i][coluna+j]] += 1;
            
        }
    }
    return 1;
}



int main(){
    int n;
    char* resposta;

    scanf("%d", &n);

    for (int k = 1; k <=n; k++){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                scanf("%d", &matriz[i][j]);
            }
        }
        printf("Instancia %d\n", k);

        resposta = "SIM";

        for (int i = 0; i < 9; i++){
            if (!mesmalinha(i) || !mesmacoluna(i) || !mesmamatrizI(i)){
                resposta = "NAO";
                break;
            }
        }

        printf("%s\n\n", resposta);
    }
    
    return 0;    
}
