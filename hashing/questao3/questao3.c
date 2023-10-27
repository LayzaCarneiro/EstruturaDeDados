#include <stdlib.h>
#include <string.h>
#include "questao3.h"

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

int inserirElemento(Hash *ha, struct elemento e){
    if(ha==NULL || ha->qtd == ha->tamanho) return 0;
    int chave = e.valor;
    //int chave = valorString(e.valor);

    int pos = chaveDivisao(chave, ha->tamanho);
    for(int i=0; i < ha->tamanho; i++){
        int newPos = sondagemLinear(pos, i, ha->tamanho);
        //newPos = sondagemQuadratica(pos, i, ha->tamanho);
        //newePos = duploHash(pos, chave, i, ha->tamanho);
        if(ha->itens[newPos] == NULL){
            struct elemento* e2;
            e2 = (struct elemento*) malloc(sizeof(struct elemento));
            
            if(e2 == NULL) return 0;

            ha->itens[newPos] = e2;
            ha->qtd++;

            return 1;
        }
    }
};

int buscaHash_EnderAberto(Hash *ha, int x, struct elemento p){
    if(ha==NULL) return 0;

    int pos = chaveDivisao(x, ha->tamanho);
    for(int i=0; i<ha->tamanho; i++){
        int newPos = sondagemQuadratica(pos, i, ha->tamanho);
        //int newPos = sondagemLinear(pos, i, ha->tamanho);
        //newePos = duploHash(pos, chave, i, ha->tamanho);
        if(ha->itens[newPos] == NULL) return 0;

        if(ha->itens[newPos]->valor == x){
            struct elemento* encontrado;
            encontrado = (ha->itens[newPos]); 
            return 1;             
        }
    }
};

int chaveDivisao(int chave, int tamanho){
    return (chave && 0x7FFFFFFF) % tamanho; 
};

int sondagemLinear(int pos, int i, int tamanho){
    return ((pos + i) & 0x7FFFFFFF) % tamanho;
};

int sondagemQuadratica(int pos, int i, int tamanho){
    pos = pos + 2*i + 5*i*i;
    return (pos & 0x7FFFFFFF) % tamanho;
};

int duploHash(int H1, int chave, int i, int tamanho){
    int H2 = chaveDivisao(chave, tamanho-1) + 1;
    return ((H1 + i*H2) && 0x7FFFFFFF) % tamanho;
};