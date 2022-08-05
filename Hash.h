#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item_d item;
struct item_d{
    char *chave;
    int cont;
    item *next;
};

typedef struct{
    item ** itens;
    int tam;
    int quantItens;
}tabela;

//Função para inicializar tabela hash.
tabela * init(int tam); 
//Função Hash.
int hash(char *chave, int M);
//Função para inicializa item.
item * itemInit(char *chave, int cont);
//Funçõa insere item na table hash.
void insere(tabela *HT, char *chave, int cont);
//Função para tratar casos de colisões usando lista ligada.
void trataColisao(tabela *HT, item *novo, int index);
//Função devolve conteudo do item caso ele esteja na tabela e -1 caso contrario.
int busca(tabela *HT, char *chave);
int buscaHT(item *ptr, char *chave);
//Desaloca tabela Hash.
void deletaHT(tabela *HT);