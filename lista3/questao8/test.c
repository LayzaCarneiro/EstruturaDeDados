#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char dado;
    struct no *prox;
} No;

typedef struct pilha {
    No *topo;
} Pilha;

void inciarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}
int pilhaVazia(Pilha *pilha) {
    return (pilha->topo == NULL);
}

void adicionar(Pilha *pilha, char valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}
char remover(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    char valor = pilha->topo->dado;
    No *temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
    return valor;
}

int palindromo(char *palavra) {
    int tam = strlen(palavra);
    Pilha pilha;
    inciarPilha(&pilha);
    int i;
    for (i=0; i<tam; i++) {
        adicionar(&pilha, palavra[i]);
    }
    for (i = 0; i < tam; i++) {
        if (palavra[i] != remover(&pilha)) {
            printf("Não é.");
            return 0;
        }
    }
    printf("é.");
    return 1;
}

int main() {
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%spilha", palavra);
    
    if (palindromo(palavra)) {
        printf("A palavra '%spilha' é um palíndromo.\n", palavra);
    } else {
        printf("A palavra '%spilha' não é um palíndromo.\n", palavra);
    }
    
    return 0;
}
