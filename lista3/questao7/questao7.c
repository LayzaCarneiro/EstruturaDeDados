#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int converteParaDecimal(int base, Pilha *pilha) {
    int decimal = 0;
    int expoente = 0;

    while (!pilhaVazia(pilha)) {
        int algarismo = remover(pilha);
        
        if (algarismo < 0 || algarismo >= base) {
            printf("Algarismo inválido para a base!\n");
            exit(1);
        }
        decimal += algarismo * pow(base, expoente);
        expoente++;
    }

    return decimal;
}


int main() {
    Pilha s;
    inicializar_pilha(&s);
    int base = 2;
    int number = 101010;
    
    while (number != 0) {
        int digit = number % base;
        adicionar(&s, digit);
        number /= base;
    }
    
    int decimal = converteParaDecimal(base, &s);
    
    printf("O número na base %d é igual a %d na base decimal.\n", base, decimal);
    
    return 0;
}