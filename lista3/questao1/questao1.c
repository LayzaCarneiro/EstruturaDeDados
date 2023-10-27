#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct no {
    int dado;
    struct no* prox;
} no;

void estaticaParaDinamica(int* estatica, int tamanho, no** dinamica) {
    no *atual, *anterior;

    for (int i= 0; i < tamanho; i++) {
        int dado = estatica[i];
        int encontrado = 0;

        atual = *dinamica;
        anterior = NULL;
        while (atual != NULL) {
            if (atual->dado == dado) {
                encontrado = 1;
                break;
            }
            anterior = atual;
            atual = atual->prox;
        }

        if (!encontrado) {
            no* novo = (no*) malloc(sizeof(no));
            novo->dado = dado;
            novo->prox = NULL;

            if (*dinamica == NULL) {
                *dinamica = novo;
            } else {
                anterior->prox = novo;
            }
        }
    }
}

int main(){
    int estatica[MAX_SIZE] = {2, 3, 5, 2, 7, 3, 8, 9, 5, 6};
    int tamanho = sizeof(estatica) / sizeof(int);

    no* dinamica = NULL;

    estaticaParaDinamica(estatica, tamanho, &dinamica);

    no* atual = dinamica;
    printf("Lista dinâmica copiada da estática: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }

    atual = dinamica;
    while (atual != NULL) {
        no* proxno = atual->prox;
        free(atual);
        atual = proxno;
    }

    return 0;
}