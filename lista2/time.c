#include <stdlib.h>
#include <stdio.h>
#include "time.h"

#define MAX_JOGADORES 22

struct jogador{
    char nome[50];
    int jogos;
    int gols;
    int assistencias;
} ;

struct time{
    char nome[50];
    Jogador jogadores[MAX_JOGADORES];
    int vitorias;
    int empates;
    int derrotas;
};

Time* atribuir(char nome[], Jogador* jogadores[], int vitorias, int empates, int derrotas){
    Time* time = (Time*) malloc(sizeof(Time));
    if(time != NULL){
        memcpy(time->jogadores, jogadores, MAX_JOGADORES * sizeof(Jogador));
        time->vitorias = vitorias;
        time->empates = empates;
        time->derrotas = derrotas;
    }
    return time;
};
void imprimir(Time* time){
    printf("Nome: %s\n", time->nome);
    printf("Jogadores:\n");
    for (int i = 0; i < MAX_JOGADORES; i++) {
        printf(" - %s (%d jogos, %d gols, %d assistencias)\n", time->jogadores[i].nome, time->jogadores[i].jogos, time->jogadores[i].gols, time->jogadores[i].assistencias);
    }
    printf("Vitorias: %i\nDerrotas: %i\nEmpates: %i\n", time->vitorias, time->derrotas, time->empates);
};
void pontuacao(Time* time){
    int pontuacao = 0;
    pontuacao += (3*(time->vitorias) + time->empates);
    printf("\nPontuação: %i\n", pontuacao);
};

int main(){
    Jogador jogadores1[MAX_JOGADORES] = {{"Jogador 1", 5, 2, 1}, {"Jogador 2", 3, 0, 3}, {"Jogador 3", 4, 1, 1}};
    Time* time1;
    time1 = atribuir("Ceará", jogadores1, 2, 1, 1);
    imprimir(time1);
    pontuacao(time1);

    return 0;
}