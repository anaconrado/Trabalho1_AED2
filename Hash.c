#include "Hash.h"

tabela *init(int tam){
    //Alocando tabela.
    tabela *HT = (tabela*)malloc(sizeof(tabela));
    //Inicializando tabela.
    HT->tam = tam;
    HT->quantItens = 0;
    //Alocando vetor de ponteiros para itens.
    HT->itens = (item**)calloc(HT->tam, sizeof(item*));
    //Inicializando vetor.
    for(int i = 0; i < HT->tam; i++){
        HT->itens[i] = NULL;
    }
    return HT;
}

int hash(char *chave, int M){
    int h = 0;
    int primo = 193;
    for(int i = 0; chave[i] != '\0'; i++){
        h = (h * primo + chave[i])%M;
    }
    return h;
}

item *itemInit(char *chave, int cont){
    //Alocando item.
    item * novo = (item*)malloc(sizeof(item));
    //Alocando string para chave.
    novo->chave = (char*)malloc(strlen(chave)+1);
    //Iniicalizando item.
    strcpy(novo->chave, chave);
    novo->cont = cont;
    novo->next = NULL;
    return novo;
}

void insere(tabela *HT, char *chave, int cont){
    int ch = hash(chave, HT->tam);
    item *novo = itemInit(chave, cont);
    //Caso de colisão (mais de um item por chave).
    if(HT->itens[ch] != NULL){
        trataColisao(HT, novo, ch);
    }
    else //Insersão normal.
        HT->itens[ch] = novo;
}

void trataColisao(tabela *HT, item *novo, int index){
    item *temp = HT->itens[index];
    //Procura final da lista ligada e o insere lá. 
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = novo;
}
//Função interface para a busca.
int busca(tabela *HT, char *chave){
    int ch = hash(chave, HT->tam);
    return buscaHT(HT->itens[ch], chave);
}

int buscaHT(item *ptr, char *chave){
    //Retorna -1 em caso não ache elemento.
    if(ptr == NULL)
        return -1;
    //Devolve conteudo do item caso chaves sejam iguais.
    if(!strcmp(ptr->chave, chave))
        return ptr->cont;
    //Busca recursivamente dentro da lista ligada.
    else
        return buscaHT(ptr->next, chave);
    
}

void deletaHT(tabela *HT){
    item *curr, *prox;
    //Loop dentro do vetor.
    for(int i = 0; i < HT->tam; i++){
        curr = HT->itens[i];
        //Loop dentro da lista ligada.
        while(curr != NULL){
            prox = curr->next;
            free(curr->chave); //Libera string.
            free(curr); //Libera item.
            curr = prox;
        }
    }
    //Libera vetor de itens e tabela.
    free(HT->itens);
    free(HT);
}