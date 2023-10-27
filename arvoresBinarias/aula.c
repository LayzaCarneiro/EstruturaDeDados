#include <stdlib.h>
#include <stdio.h>
#include "aula.h"

struct no{
    int dado;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
};

void libera_NO(struct NO* no){
    if(no == NULL) exit(1);
    libera_NO(no->esq);
    libera_NO(no->dir);
    no = NULL;
};

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL) exit(1);

    libera_NO(*raiz); // libera cada nó
    free(raiz); // libera a raiz
};

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return 1;
    if(*raiz == NULL) return 1;
    return 0;
};

int totalNO_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return 0;
    if(*raiz == NULL) return 0;

    int total_esq = totalNO_ArvBin(&((*raiz)->esq));
    int total_dir = totalNO_ArvBin(&((*raiz)->dir));

    return (total_esq + total_dir + 1);
};

int altura_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return 0;
    if(*raiz == NULL) return 0;

    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));

    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
};

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return 0;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
};

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return 0;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
};

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return 0;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
};

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL) return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info) return 1;
        else if(valor > atual->info) 
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
};

int menorValor_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return 0;
    struct NO* atual = *raiz;
    
    while(atual->esq != NULL)
        atual = atual->esq;

    return atual;
};

int maiorValor_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return 0;
    struct NO* atual = *raiz;
    
    while(atual->dir != NULL)
        atual = atual->dir;
        ,l
    return atual;
};

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL) return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));

    if(novo == NULL) return 0;

    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL) 
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0; // elemento já existe
            }
            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else    
            ant->esq = novo;
    }
    return 1;    
};

int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL) return 0;
    
    struct NO* atual = *raiz;
    struct NO* ant = NULL;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > ant->info)
            ant->dir = novo;
        else    
            ant->esq = novo;
    }
    return 0;    
}

struct NO* remove_atual(struct *NO atual){
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}