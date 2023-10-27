#include <stdio.h>
#define MAX 100

int pilha1[MAX], pilha2[MAX];
int topo1 = -1, topo2 = MAX;

void empilha(int A[], int pilha, int valor) {
    if (pilha == 1) {
        if (topo1 == topo2 - 1) { 
            printf("Erro: pilha 1 cheia\n");
            return;
        }
        topo1++;
        pilha1[topo1] = valor;
    } else if (pilha == 2) {
        if (topo2 == topo1 + 1) {
            printf("Erro: pilha 2 cheia\n");
            return;
        }
        topo2--;
        pilha2[topo2] = valor;
    } else {
        printf("Erro: pilha %d não existe\n", pilha);
    }
}

int desempilha(int pilha) {
    int valor;
    if (pilha == 1) { 
        if (topo1 == -1) {
            printf("Erro: pilha 1 vazia\n");
            return -1;
        }
        valor = pilha1[topo1];
        topo1--;
    } else if (pilha == 2) { 
        if (topo2 == MAX) { 
            printf("Erro: pilha 2 vazia\n");
            return -1;
        }
        valor = pilha2[topo2];
        topo2++;
    } else {
        printf("Erro: pilha %d não existe\n", pilha);
        return -1;
    }
    return valor;
}
