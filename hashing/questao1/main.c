#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "questao1.h"

Hash* criaHash(int tamanho){
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        ha->tam = tamanho;
        ha->itens = (struct elemento**) malloc(tamanho*sizeof(struct elemento*));
        if(ha->itens==NULL){
            free(ha);
            return NULL;
        }
        ha->qtd=0;
        for(int i=0; i < ha->tam; i++) ha->itens[i] = NULL;
    }
    return ha;
};

void liberaHash(Hash* ha){
    if(ha != NULL){
        for(int i=0; i < ha->tam; i++){
            if(ha->itens[i] != NULL) free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha); 
    }
};

int chaveDivisao(int chave, int tamanho){
    return (chave && 0x7FFFFFFF) % tamanho; 
};

int valorString(char *str){
    int valor=7;
    int tam = strlen(str);
    for(int i=0; i<tam; i++)
        valor = 31*valor + (int) str[i];
    return valor;
};

int insereCidade(Hash* ha, struct elemento cidade){
    if(ha == NULL || ha->qtd == ha->tam)
        return 0;

    int chave = valorString(cidade.nome);
    int pos = chaveDivisao(chave, ha->tam);
    struct elemento* novo = (struct elemento*)malloc(sizeof(struct elemento));
    if(novo == NULL)
       return 0;
    *novo = cidade;
    novo->prox = NULL;
    if(ha->itens[pos] == NULL){
        ha->itens[pos] = novo;
    }else{
        struct elemento* aux = ha->itens[pos];
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    ha->qtd++;
    return 1;
}

void imprimeColisao(Hash* ha){
    if(ha->qtd == 0){
        printf("Tabela vazia.");
    }
    int col = 0;
    int numEnder[11] = {0};
    for(int i = 0; i < ha->tam; i++){
        int cont = 0;
        if(ha->itens[i] != NULL){
            struct elemento* aux = ha->itens[i];
            while(aux != NULL){
                cont++;
                aux = aux->prox;
            }
            if(cont > 1)
                col++;
            if(cont <= 10)
                numEnder[cont]++;    
            else
                numEnder[10]++;
        }else
            numEnder[0]++;

        printf("Endereco: %d\n",i);
        struct elemento *aux = ha->itens[i];
        while(aux != NULL){
            printf("%s\n", aux->nome);
            aux = aux->prox;
        }
        printf("\n");
    }
    printf("\nNumero de colisoes: %d\n", col);
    for(int i = 0; i<=10; i++){
        printf("Numero de enderecos com %d cidade(s): %d\n", i, numEnder[i]);
    }
    printf("Numero de enderecos com mais de 10 cidades associadas: %d\n", numEnder[10]);
}

int main() {
    Hash* ha = criaHash(35);
    struct elemento cidades[31] = {
        {"Acarape"},
        {"Acarau"},
        {"Aquiraz"},
        {"Aracati"},
        {"Acarauzinho"},
        {"Aratuba"},
        {"Assare"},
        {"Aracoiaba"},
        {"Canindé"},
        {"Cascavel"},
        {"Caucaia"},
        {"Crato"},
        {"Cruz"},
        {"Caponguinha"},
        {"Croata"},
        {"Fortaleza"},
        {"Farias Brito"},
        {"Forquilha"},
        {"Frecheirinha"},
        {"Pacajus"},
        {"Pacatuba"},
        {"Paraipaba"},
        {"Paracuru"},
        {"Paramoti"},
        {"Pentecoste"},
        {"Palmácia"},
        {"Pindoretama"},
        {"Poranga"},
        {"Pacoti"},
        {"Potiretama"},
    };

    for (int i = 0; i<31; i++) {
        insereCidade(ha, cidades[i]);
    }
    imprimeColisao(ha);
    liberaHash(ha);

    return 0;
}