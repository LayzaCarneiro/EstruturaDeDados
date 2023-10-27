#include <stdlib.h>
#include <string.h>
#include "questao5.h"

struct hash{
    int qtd, TABLE_SIZE;
    struct produto **itens;
};

Hash* criaHash(int tamanho){
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        ha->TABLE_SIZE=tamanho;
        ha->itens = (struct aluno**) malloc(tamanho*sizeof(struct aluno*));
        if(ha->itens==NULL){
            free(ha);
            return NULL;
        }
        ha->qtd=0;
        for(int i=0; i<ha->TABLE_SIZE; i++) ha->itens[i] = NULL;
    }
    return ha;
};

void liberaHash(Hash* ha){
    if(ha != NULL){
        for(int i=0; i<ha->TABLE_SIZE; i++){
            if(ha->itens[i] != NULL) free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha); 
    }
};

int chaveDivisao(int chave, int tamanho){
    return (chave && 0x7FFFFFFF) % tamanho; 
};

int inserirProduto(Hash* ha, struct produto p){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE) return 0;

    int pos = chaveDivisao(p.codigo, ha->TABLE_SIZE);
    struct produto* novo;
    novo = (struct produto*) malloc(sizeof(struct produto));
    if(novo == NULL) return 0;
    ha->itens[pos] = novo;
    ha->qtd++;
    
    return 1;
};

int buscarProduto(Hash* ha, int codigo){
    if(ha == NULL) return 0;
    int pos = chaveDivisao(codigo, ha->TABLE_SIZE);
    if(ha->itens[pos]==NULL) return 0;
    struct produto p = (*ha->itens[pos]);

    return 1;
};

int atualizarProduto(Hash* ha, struct produto p, double preco){
    if(ha == NULL) return 0;
    int pos = chaveDivisao(p.codigo, ha->TABLE_SIZE);
    if(ha->itens[pos]==NULL) return 0;
    ha->itens[pos]->preco = preco;

    return 1;
};

int removerProduto(Hash* ha, struct produto p){
    if(ha == NULL) return 0;
    int pos = chaveDivisao(p.codigo, ha->TABLE_SIZE);
    if(ha->itens[pos]==NULL) return 0;
    
    free(ha->itens[pos]);
    ha->qtd--;

    return 1;
};

int produtoMaisCaro(Hash* ha){
    if(ha == NULL) return 0;

    double prodMaisCaro=0;
    for(int i=0; i<ha->TABLE_SIZE; i++){
        if((ha->itens[i]->preco) > prodMaisCaro) prodMaisCaro = ha->itens[i]->preco;
    }
};