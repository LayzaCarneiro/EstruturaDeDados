#include <stdlib.h>
#include <string.h>
#include "aula.h"

struct hash{
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

// ENCADEAMENTO SEPARADO: Armazena dentro de cada posição da tabela o início de uma lista dinâmica encadeada
// ENDEREÇAMENTO ABERTO: 

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
    return (chave & 0x7FFFFFFF) % tamanho; 
};

int valorString(char *str){
    int valor=7;
    int tam = strlen(str);
    for(int i=0; i<tam; i++)
        valor = 31*valor + (int) str[i];
    return valor;
};

int insereHash_SemColisao(Hash *ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    
    int chave = al.matricula;
    //int chave = valorString(al.nome);

    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    struct aluno* novo;
    novo = (struct aluno*) malloc(sizeof(struct aluno));
    if(novo == NULL) return 0;
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    
    return 1;
};

int buscaHash_SemColisao(Hash *ha, int mat, struct aluno al){
    if(ha== NULL) return 0;
    int pos = chaveDivisao(mat, ha->TABLE_SIZE);

    if(ha->itens[pos]==NULL) return 0;
    *al = *(ha->itens[pos]);

    return 1;
};

int insereHash_EnderAberto(Hash *ha, struct aluno al){
    if(ha==NULL || ha->qtd==ha->TABLE_SIZE) return 0;
    int chave = al.matricula;
    //int chave = valorString(al.nome);

    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    for(int i=0; i<ha->TABLE_SIZE; i++){
        int newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        //newPos = sondagemQuadratica(pos, i, ha->TABLE_SIZE);
        //newePos = duploHash(pos, chave, i, ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL){
            struct aluno* novo;
            novo = (struct aluno*) malloc(sizeof(struct aluno));
            if(novo == NULL) return 0;
            *novo = al;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }
};

int buscaHash_EnderAberto(Hash *ha, int mat, struct aluno al){
    if(ha==NULL) return 0;

    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    for(int i=0; i<ha->TABLE_SIZE; i++){
        int newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        //newPos = sondagemQuadratica(pos, i, ha->TABLE_SIZE);
        //newePos = duploHash(pos, chave, i, ha->TABLE_SIZE);
        if(ha->itens[newPos] == NULL) return 0;

        if(ha->itens[newPos]->matricula == mat){
            *al = *(ha->itens[newPos]);
            return 1;
        }
    }
};
