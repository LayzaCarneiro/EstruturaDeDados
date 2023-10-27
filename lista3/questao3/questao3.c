#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char letra;
    struct no *prox;
} No;

void removeNos(No **no, No *l2, No *l3) {
    No *atual, *anterior;
    int i, j;
    int index1, index2;
    int contador = 1;
    
    atual = *no;
    anterior = NULL;
    while (atual != NULL) {
        index1 = -1;
        index2 = -1;
        for (i=1, j=1; l2 != NULL || l3 != NULL; i++, j++) {
            if (l2 != NULL && l2->letra == i) {
                index1 = contador;
                l2 = l2->prox;
            }
            if (l3 != NULL && l3->letra == j) {
                index2 = contador;
                l3 = l3->prox;
            }
        }
        if (index1 == contador || index2 == contador) {
            if (anterior == NULL) {
                *no = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            No *temp = atual;
            atual = atual->prox;
            free(temp);
        } else {
            anterior = atual;
            atual = atual->prox;
            contador++;
        }
    }
}

void imprimir(No *no) {
    No *atual = no;
    while (atual != NULL) {
        printf("%c ", atual->letra);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    No *l1 = (No*) malloc(sizeof(No));
    l1->letra = 'A';
    l1->prox = (No*) malloc(sizeof(No));
    l1->prox->letra = 'B';
    l1->prox->prox = (No*) malloc(sizeof(No));
    l1->prox->prox->letra = 'C';
    l1->prox->prox->prox = (No*) malloc(sizeof(No));
    l1->prox->prox->prox->letra = 'D';
    l1->prox->prox->prox->prox = (No*) malloc(sizeof(No));
    l1->prox->prox->prox->prox->letra = 'E';
    l1->prox->prox->prox->prox->prox = NULL;
    
    No *l2 = (No*) malloc(sizeof(No));
    l2->letra = '2';
    l2->prox = (No*) malloc(sizeof(No));
    l2->prox->letra = '4';
    l2->prox->prox = (No*) malloc(sizeof(No));
    l2->prox->prox->letra = '8';
    l2->prox->prox->prox = NULL;
    
    No *l3 = (No*) malloc(sizeof(No));
    l3->letra = '2';
    l3->prox = (No*) malloc(sizeof(No));
    l3->prox->letra = '5';
    l3->prox->prox = NULL;
    
    printf("Antes da remoção: ");
    imprimir(l1);
    
    removeNos(&l1, l2, l3);
    
    printf("Depois da remoção: ");
    imprimir(l1);
    
    return 0;
}
