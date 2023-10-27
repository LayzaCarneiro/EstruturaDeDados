#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
  int itens[MAX];
  int inicio;
  int fim;
  int qtd;
} Fila;

typedef struct {
  int itens[MAX];
  int topo;
} Pilha;

void inicializa_fila(Fila* fila) {
  fila->inicio = 0;
  fila->fim = -1;
  fila->qtd = 0;
}
int fila_vazia(Fila* fila) {
  return fila->qtd == 0;
}
int fila_cheia(Fila* fila) {
  return fila->qtd == MAX;
}
void enfileira(Fila* fila, int dado) {
  if (!fila_cheia(fila)) {
    fila->fim = (fila->fim + 1) % MAX;
    fila->itens[fila->fim] = dado;
    fila->qtd++;
  }
}
int desenfileira(Fila* fila) {
  if (!fila_vazia(fila)) {
    int dado = fila->itens[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX;
    fila->qtd--;
    return dado;
  }
  return -1;
}

void inicializa_pilha(Pilha* pilha) {
  pilha->topo = -1;
}

int pilha_vazia(Pilha* pilha) {
  return pilha->topo == -1;
}

int pilha_cheia(Pilha* pilha) {
  return pilha->topo == MAX - 1;
}

void empilha(Pilha* pilha, int dado) {
  if (!pilha_cheia(pilha)) {
    pilha->topo++;
    pilha->itens[pilha->topo] = dado;
  }
}

int desempilha(Pilha* pilha) {
  if (!pilha_vazia(pilha)) {
    int dado = pilha->itens[pilha->topo];
    pilha->topo--;
    return dado;
  }
  return -1;
}

void inverte_fila_estatica(Fila* fila) {
  Pilha pilha;
  inicializa_pilha(&pilha);
  while (!fila_vazia(fila)) {
    empilha(&pilha, desenfileira(fila));
  }
  while (!pilha_vazia(&pilha)) {
    enfileira(fila, desempilha(&pilha));
  }
}

void imprime_fila_estatica(Fila* fila) {
  int i = fila->inicio;
  for (int j = 0; j < fila->qtd; j++) {
    printf("%d ", fila->itens[i]);
    i = (i + 1) % MAX;
  }
  printf("\n");
}

int main() {
  Fila fila;
  inicializa_fila(&fila);
  enfileira(&fila, 1);
  enfileira(&fila, 2);
  enfileira(&fila, 3);
  enfileira(&fila, 4);
  printf("Fila antes da inversão: ");
  imprime_fila_estatica(&fila);
  inverte_fila_estatica(&fila);
  printf("Fila depois da inversão: ");
  imprime_fila_estatica(&fila);
  return 0;
}
