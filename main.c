#include "Hash.h"

int main(){

    int participantes;
    int quantPalavras;

    scanf("%d %d", &quantPalavras, &participantes);
    tabela * HT = init(quantPalavras);
    //Inserção na tabela hash das palavras.
    for(int i = 0; i < quantPalavras; i++){
        int valor; 
        char *palavra = (char *) malloc(30 * sizeof(char)); 
        scanf("%s %d", palavra, &valor);
        insere(HT, palavra, valor);
        free(palavra);
    }

    for(int i = 0; i < participantes; i++){
        int pontuacao = 0;
        int fim = 0;
        //Loop lê cada palavra e faz a busca dentro da hash.    
        while(!fim){
            char *str = (char *) malloc(30 * sizeof(char));
            scanf("%s", str);
            if(str[0] != '.'){
                int cont = busca(HT, str);
                //Cálculo da pontuação.
                if(cont != -1) 
                    pontuacao += cont; 
                else
                    pontuacao -= 10;
            }
            else
                fim = 1;
            free(str);
        }
        printf("%d\n", pontuacao);
    }
    deletaHT(HT); //Destruindo a tabela.
    
    return 0;
}

