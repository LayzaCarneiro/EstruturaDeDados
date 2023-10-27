#include <stdlib.h>
#include <string.h>
#include "questao4.h"

struct hash{
    int qtd, TABLE_SIZE;
    struct aluno **itens;
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

int insereAluno(Hash *ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE) return 0;
    
    int chave = al.matricula;

    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct aluno* novo;
    novo = (struct aluno*) malloc(sizeof(struct aluno));
    if(novo == NULL) return 0;
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    
    return 1;
};

int buscaAluno(Hash *ha, int mat, struct aluno al){
    if(ha== NULL) return 0;
    int pos = chaveDivisao(al.matricula, ha->TABLE_SIZE);

    if(ha->itens[pos]==NULL) return 0;
    al = *(ha->itens[pos]);

    return 1;
};

int removeAluno(Hash *ha, struct aluno al){
    if(ha == NULL) return 0;
    int pos = chaveDivisao(al.matricula, ha->TABLE_SIZE);

    if(ha->itens[pos]==NULL) return 0;
    free(ha->itens[pos]);
    
    ha->qtd--;

    return 1;
};

int mediaAluno(Hash *ha){
    if(ha == NULL) return 0;
    int pos=0, media=0;
    while(pos<ha->TABLE_SIZE){
        media += ha->itens[pos]->matricula;
    }
    return media;
};
