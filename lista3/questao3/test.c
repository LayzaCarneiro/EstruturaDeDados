#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char dado;
    struct no *prox;
} No;

void removerNos(No **no, int *l2, int tam2, int *l3, int tam3) {
    int i, j, k;
    No *ant, *atual;
    int pos = 0;
    
    ant = NULL;
    atual = *no;
    while (atual != NULL) {
        if (pos < tam2 && (l2[pos]-1) == pos) pos++;
        else {
            for (i=0; i < tam3; i++) {
                if ((l3[i]-1) == pos) {
                    pos++;
                    break;
                }
            }if (i==tam3) {
                if(ant == NULL) *no = atual->prox;
                else ant->prox = atual->prox;
                No *temp = atual;
                atual = atual->prox;
                free(temp);
            }
            else {
                ant = atual;
                atual = atual->prox;
                pos++;
            }
        }
    }
}
