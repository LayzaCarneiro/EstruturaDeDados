#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Ponto.h"

struct ponto{
    float x;
    float y;
};

Ponto* cria(float x, float y){
    Ponto* p = (Ponto*) malloc(sizeof(Ponto)); 
    if(p == NULL){
        printf("Memória insuficiente!\n");
        exit(1);
    }
    p->x = x;
    p->y = y;
    return p;
};
void libera(Ponto* p){
    free(p);
};
int acessa(Ponto* p){
    printf(" X = %f\n Y = %f\n", p->x, p->y);

    return 0;
};
void atribui(Ponto* p, float x, float y){
    p->x = x;
    p->y = y;
};
float distancia(Ponto* p1, Ponto* p2){
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx*dx + dy*dy);
};

int somaPontos(Ponto* p, Ponto* q){
    Ponto* resultado = cria(0, 0);
    resultado->x = p->x + q->x;
    resultado->y = p->y + q->y;
    printf("x = %f e y = %f\n", resultado->x, resultado->y);

    return 0;
};
int subtracaoPonto(Ponto* p, Ponto* q){
    Ponto* resultado = cria(0, 0);
    resultado->x = p->x - q->x;
    resultado->y = p->y - q->y;
    printf("x = %f e y = %f\n", resultado->x, resultado->y);

    return 0;
};

int main(){
    Ponto* p;
    Ponto* q;
    p = cria(10, 21);
    q = cria(7, 25);
    printf("Coordenadas do ponto p: \n" + acessa(p));
    printf("Coordenadas do ponto q: \n" + acessa(q));
    printf("Distância entre os pontos p e q: %f\n", distancia(p, q));

    atribui(p, 7, 30);
    atribui(q, 15, 21);

    printf("Novas coordenadas do ponto p: \n" + acessa(p));
    printf("Novas coordenadas do ponto q: \n" + acessa(q));

    printf("Soma de p e q: " + somaPontos(p, q));

    libera(p);
    libera(q);

    return 0;
}