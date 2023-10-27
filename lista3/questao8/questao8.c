#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct pilha {
    No *topo;
} Pilha;

void inicializar_pilha(Pilha *s) {
    s->topo = NULL;
}
int pilhaVazia(Pilha *s) {
    return (s->topo == NULL);
}
void adicionar(Pilha *s, int valor) {
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->prox = s->topo;
    s->topo = novoNo;
}
int remover(Pilha *s) {
    if (pilhaVazia(s)) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    int valor = s->topo->dado;
    No *temp = s->topo;
    s->topo = s->topo->prox;
    free(temp);
    return valor;
}

int verificaPalindromo(char *palavra) {
    int tam = strlen(palavra);
    Pilha *pilha = inicializar_pilha(pilha); 
    int i;

    for (i = 0; i < tam/2; i++) {
        adicionar(pilha, palavra[i]);
    }

    if (tam % 2 != 0) { 
        i++;
    }
    while (i < tam) {
        if (palavra[i] != remover(pilha)) {
            free(pilha);
            printf("Não é palíndromo.")
            return 0; 
        }
        i++;
    }
    printf("É palíndromo.")
    free(pilha);
    return 1; 
}


//Uma estrutura de dados adequada para resolver este problema é a pilha. A ideia é empilhar os caracteres da primeira metade da palavra e, em seguida, desempilhar os caracteres da segunda metade da palavra e compará-los com os caracteres desempilhados da primeira metade. Se os caracteres forem iguais, a palavra é um palíndromo. Caso contrário, a palavra não é um palíndromo.