#include <stdlib.h>
#include <stdio.h>
#include "jogador.h"

struct jogador{
    char nome[50];
    int jogos;
    int gols;
    int assistencias;
};

Jogador* atribuir(char nome[], int jogos, int gols, int assistencias){
    Jogador* jogador = (Jogador*) malloc(sizeof(Jogador));
    if(jogador != NULL){
        jogador->nome, nome;
        jogador->jogos = jogos;
        jogador->gols = gols;
        jogador->assistencias = assistencias;
    }
    return jogador;
};
void imprimir(Jogador* jogador){
    printf("Nome: %c\n Jogos: %i\n Gols: %i\n Assistencias: %i\n", jogador->nome, jogador->jogos, jogador->gols, jogador->assistencias);
};
void bomJogador(Jogador* jogador){
    if(jogador->gols/jogador->jogos > 0.5 || jogador->assistencias/jogador->jogos > 0.5) printf("%c Eh Bom jogador!\n", jogador->nome);
    else printf("%c Eh Mal jogador!!\n", jogador->nome);
};

int main(){
    Jogador* Samuel;
    Jogador* Italo;
    Samuel = atribuir("Samuel", 10, 7, 2);
    Italo = atribuir("Italo", 12, 4, 5);

    imprimir(Samuel);
    imprimir(Italo);

    bomJogador(Samuel);
    bomJogador(Italo);
    
    return 0;
}