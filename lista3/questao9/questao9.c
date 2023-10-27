#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int dado[MAX];
    int inicio;
    int final;
} Fila;

typedef struct {
    Fila fila1;
    Fila fila2;
} Pilha;

void iniciarFila(Fila *q) {
    q->inicio = q->final = -1;
}

int filaVazia(Fila *q) {
    return q->inicio == -1;
}

int filaCheia(Fila *q) {
    return (q->final + 1) % MAX == q->inicio;
}

void enfileirar(Fila *q, int x) {
    if (filaCheia(q)) {
        printf("Fila cheia!\n");
        exit(1);
    }
    if (filaVazia(q)) {
        q->inicio = q->final = 0;
    } else {
        q->final = (q->final + 1) % MAX;
    }
    q->dado[q->final] = x;
}

int desenfileirar(Fila *q) {
    if (filaVazia(q)) {
        printf("Fila vazia!\n");
        exit(1);
    }
    int x = q->dado[q->inicio];
    if (q->inicio == q->final) {
        iniciarFila(q);
    } else {
        q->inicio = (q->inicio + 1) % MAX;
    }
    return x;
}

void push(Pilha *s, int x) {
    enfileirar(&s->fila1, x);
}

int pop(Pilha *s) {
    if (filaVazia(&s->fila1) && filaVazia(&s->fila2)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    while (!filaVazia(&s->fila1)) {
        enfileirar(&s->fila2, desenfileirar(&s->fila1));
    }
    int x = desenfileirar(&s->fila2);
    while (!filaVazia(&s->fila2)) {
        enfileirar(&s->fila1, desenfileirar(&s->fila2));
    }
    return x;
}

int main() {
    Pilha s;
    iniciarFila(&s.fila1);
    iniciarFila(&s.fila2);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s)); // 3
    printf("%d\n", pop(&s)); // 2
    printf("%d\n", pop(&s)); // 1
    printf("%d\n", pop(&s)); // Pilha underflow!
    return 0;
}
