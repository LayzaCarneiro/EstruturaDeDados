#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
struct no {
    int valor;
    No* proximo;
    No* anterior;
};

typedef struct fila Fila;
struct fila {
    No* inicio;
    No* fim;
    int tamanho;
};

Fila* criar_fila() {
    Fila* nova_fila = (Fila*) malloc(sizeof(Fila));
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
    nova_fila->tamanho = 0;
    return nova_fila;
}

void enfileirar(Fila* fila, int valor) {
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo_no;
        fila->fim = novo_no;
        novo_no->anterior = NULL;
    } else {
        novo_no->anterior = fila->fim;
        fila->fim->proximo = novo_no;
        fila->fim = novo_no;
    }

    fila->tamanho++;
}

int desenfileirar(Fila* fila) {
    if (fila->inicio == NULL) {
        return -1;
    }

    No* no_removido = fila->inicio;
    int valor_removido = no_removido->valor;

    if (fila->inicio == fila->fim) {
        fila->inicio = NULL;
        fila->fim = NULL;
    } else {
        fila->inicio = no_removido->proximo;
        fila->inicio->anterior = NULL;
    }

    free(no_removido);
    fila->tamanho--;

    return valor_removido;
}

int fila_vazia(Fila* fila) {
    return (fila->inicio == NULL);
}

int tamanho_fila(Fila* fila) {
    return fila->tamanho;
}

