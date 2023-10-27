#include <stdio.h>
#include <stdlib.h>
#include "questao2.h"

struct elemento {
  int dado;
  Elemento* prox;
  Elemento* ant;
};

struct lista {
  Elemento* inicio;
  Elemento* fim;
  int qtd;
};

Lista* cria_lista(){
  Lista* lista = (Lista*) malloc(sizeof(Lista));
  if (lista != NULL) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
  }
  return lista;
}

int inserir_elemento(Lista* lista, int dado) {
  Elemento* novo_elemento = (Elemento*) malloc(sizeof(Elemento));
  if (novo_elemento == NULL) return 0;
  
  novo_elemento->dado = dado;
  novo_elemento->prox = NULL;
  novo_elemento->ant = NULL;

  if (lista->inicio == NULL) {
    lista->inicio = novo_elemento;
    lista->fim = novo_elemento;
  } else {
    novo_elemento->ant = lista->fim;
    lista->fim->prox = novo_elemento;
    lista->fim = novo_elemento;
  }

  lista->qtd++;
  return 1;
}

int remove_elemento(Lista* lista, int valor) {
  Elemento* atual = lista->inicio;
  while (atual != NULL) {
    if (atual->dado == dado) {
      if (atual == lista->inicio && atual == lista->fim) {
        lista->inicio = NULL;
        lista->fim = NULL;
      } else if (atual == lista->inicio) {
        lista->inicio = atual->prox;
        lista->inicio->ant = NULL;
      } else if (atual == lista->fim) {
        lista->fim = atual->ant;
        lista->fim->prox = NULL;
      } else {
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
      }
      free(atual);
      lista->qtd--;
      return 1;
    }
    atual = atual->prox;
  }
  return 0;
}