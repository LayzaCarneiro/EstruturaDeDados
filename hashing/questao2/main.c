#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questao2.h"

struct hash{
    int qtd, tamanho;
    struct elemento **itens;
};

Hash* criaHash(int tamanho){
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        ha->tamanho = tamanho;
        ha->itens = (struct elemento**) malloc(tamanho*sizeof(struct elemento*));
        if(ha->itens==NULL){
            free(ha);
            return NULL;
        }
        ha->qtd=0;
        for(int i=0; i < ha->tamanho; i++) ha->itens[i] = NULL;
    }
    return ha;
};

void liberarHash(Hash* ha){
    if(ha != NULL){
        for(int i=0; i < ha->tamanho; i++){
            if(ha->itens[i] != NULL) free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha); 
    }
};

int chaveDivisao(int chave, int tamanho){
    return (chave && 0x7FFFFFFF) % tamanho; 
};

int inserirElemento(Hash *ha, struct elemento e){
    if(ha == NULL || ha->qtd == ha->tamanho) return 0;
    
    int chave = e.valor;
    int pos = chaveDivisao(chave, ha->tamanho);

    struct elemento* e2 = (struct elemento*) malloc(sizeof(struct elemento));
    if(e2 == NULL) return 0;
    ha->itens[pos] = e2;
    ha->qtd++;
    
    return 1;
};

int buscarElemento(Hash *ha, struct elemento e){
    if(ha == NULL) return 0;
    int pos = chaveDivisao(e.valor, ha->tamanho);

    if(ha->itens[pos]==NULL) return 0;
    struct elemento* encontrado = (ha->itens[pos]);

    return 1;
};

int deletarElemento(Hash *ha, struct elemento e){
    if(ha == NULL) return 0;
    int pos = chaveDivisao(e.valor, ha->tamanho);

    if(ha->itens[pos]==NULL) return 0;
    free(ha->itens[pos]);
    
    ha->qtd--;

    return 1;
};