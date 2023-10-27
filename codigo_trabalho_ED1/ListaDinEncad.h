#ifndef LISTADINENCAD_H
#define LISTADINENCAD_H
#include "AVLTree.h"

typedef struct elementoLista *Lista;
struct elementoLista{
    struct telefone dados;
    struct elementoLista *prox;
};
typedef struct elementoLista ElemLista;

Lista *cria_lista();
void libera_lista(Lista *li); 
int insere_lista_final(Lista *li, struct telefone al); 
int insere_lista_inicio(Lista *li, struct telefone *al); 
int tamanho_lista(Lista *li); 
void ordernarLista(Lista *li); 
#endif

