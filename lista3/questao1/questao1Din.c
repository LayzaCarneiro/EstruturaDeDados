#include <stdio.h>
#include <stdlib.h>
#define MAX_tamanho 100

typedef struct no {
    int dado;
    struct no *prox;
} No;

void dinamicaParalistaEstatica(No *no, int *estatica, int *tamanho) {
    No *atual;
    int *listaEstatica = (int*) malloc(sizeof(int) * MAX_tamanho); 
    
    int i = 0, j;
    atual = no;
    while (atual != NULL && i < MAX_tamanho) {
        for (j=0; j < i; j++) {
            if (listaEstatica[j] == atual->dado) break;
        }if (j == i) {
            listaEstatica[i] = atual->dado;
            i++;
        }
        atual = atual->prox;
    }
    for (j=0; j < i; j++) {
        estatica[j] = listaEstatica[j];
    }
    *tamanho = i;
    free(listaEstatica);
}

int main() {
    No *no = (No*) malloc(sizeof(No));
    no->dado = 1;
    no->prox = (No*) malloc(sizeof(No));
    no->prox->dado = 2;
    no->prox->prox = (No*) malloc(sizeof(No));
    no->prox->prox->dado = 3;
    no->prox->prox->prox = (No*) malloc(sizeof(No));
    no->prox->prox->prox->dado = 2;
    no->prox->prox->prox->prox = (No*) malloc(sizeof(No));
    no->prox->prox->prox->prox->dado = 5;
    no->prox->prox->prox->prox->prox = (No*) malloc(sizeof(No));
    no->prox->prox->prox->prox->prox->dado = 7;
    no->prox->prox->prox->prox->prox->prox = NULL;
    
    int estatica[MAX_tamanho];
    int tamanho;
    
    dinamicaParalistaEstatica(no, estatica, &tamanho);
    
    printf("Lista estática copiada da dinâmica: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", estatica[i]);
    }
    printf("\n");
    
    return 0;
}
