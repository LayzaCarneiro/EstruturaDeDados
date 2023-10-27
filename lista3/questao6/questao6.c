#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TAM 100

typedef struct {
    int topo;
    char dados[MAX_TAM];
} Pilha;

void inicia_pilha(Pilha *pilha) {
    pilha->topo = -1;
}

int pilha_vazia(Pilha *pilha) {
    return (pilha->topo == -1);
}

int pilha_cheia(Pilha *pilha) {
    return (pilha->topo == MAX_TAM-1);
}

void empilha(Pilha *pilha, char dado) {
    if (pilha_cheia(pilha)) {
        printf("Erro: a pilha está cheia\n");
        exit(EXIT_FAILURE);
    } else {
        pilha->topo++;
        pilha->dados[pilha->topo] = dado;
    }
}

char desempilha(Pilha *pilha) {
    if (pilha_vazia(pilha)) {
        printf("Erro: a pilha está vazia\n");
        exit(EXIT_FAILURE);
    } else {
        char dado = pilha->dados[pilha->topo];
        pilha->topo--;
        return dado;
    }
}

int verificaParenteses(char *expressao) {
    Pilha pilha;
    inicia_pilha(&pilha);
    int i;

    for (i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            empilha(&pilha, '(');
        } else if (expressao[i] == ')') {
            if (pilha_vazia(&pilha)) {
                return 0; 
            } else {
                desempilha(&pilha);
            }
        }
    }

    return pilha_vazia(&pilha); 
}

int main() {
    char expressao[MAX_TAM];
    printf("Digite uma expressão: ");
    scanf("%s", expressao);

    if (verificaParenteses(expressao)) {
        printf("A expressão está com a parentização correta.\n");
    } else {
        printf("A expressão não está com a parentização correta.\n");
    }

    return 0;
}
