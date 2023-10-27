#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questao2.h"

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL){
       *raiz = NULL;
    }
    return raiz;
}

int insere_ArvBin(ArvBin* raiz, int id, int ano, char autor[], char titulo[]){
    if(raiz == NULL){
        printf("arvore vazia\n");
        return 0;
    }
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    if(novo == NULL){
        printf("erro ao criar no\n");
        return 0;
    }
    novo->ano = ano;
    novo->id = id;
    strcpy(novo->autor, autor);
    strcpy(novo->titulo, titulo);
    novo->esq = NULL;
    novo->dir = NULL;
    if(*raiz == NULL){
       *raiz = novo;
    }else{
        struct No* atual = *raiz;
        struct No* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(id == atual->id){
                free(novo);
                return 0;
            }
            if(id > atual->id){
               atual = atual->dir;
            }else{
                atual = atual->esq;
            }
        }
        if(id > ant->id){
           ant->dir = novo;
        }else{
           ant->esq = novo;
        }
    }
    return 1;
}

void encontrarLivros(ArvBin* raiz, char autor[], int anoInicial, int anoFinal){
    if(raiz == NULL){
        printf("arvore vazia\n");
        return;
    }
    while((*raiz) != NULL){
        if(strcmp((*raiz)->autor, autor) == 0 && (*raiz)->ano >= anoInicial && (*raiz)->ano <= anoFinal){
            printf("Livro de %s:\n", autor);
            printf("Titulo: %s\n",(*raiz)->titulo);
            printf("Autor: %s\n", (*raiz)->autor);
            printf("ID: %d\n", (*raiz)->id);
            printf("Ano: %d\n", (*raiz)->ano);
            printf("-----------------------\n");
        }
        encontrarLivros(&((*raiz)->esq), autor, anoInicial, anoFinal);
        encontrarLivros(&((*raiz)->dir), autor, anoInicial, anoFinal);
        return;
    }
}
