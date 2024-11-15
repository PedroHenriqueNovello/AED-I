//Pedro Henrique Novello D'Elia Porto de Almeida RA: 176620

#include <stdio.h>
#include <string.h>

int main(){
    int N;
    scanf("%d", &N);
    
    

    while(N--){
        char linha [1000];
        scanf("%s\n", linha);
        
        int diamantes = 0;
        int contador = 0;  // pra contar a quantidade de < incompletos

        
        for(int i = 0; i < strlen(linha); i++){
            if (linha[i] == '<'){
                contador++;
            }
            else if(linha[i] == '>'){
                if(contador > 0){
                    contador--;
                    diamantes++;
                }
            }
        }
      printf("%d\n", diamantes);
    

    }
   
    return 0;

}
