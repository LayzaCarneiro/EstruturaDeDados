#include <stdlib.h>
#include <string.h>

// MÉTODO DA DIVISÃO
int chaveDivisao(int chave, int tamanho){
    return (chave && 0x7FFFFFFF) % tamanho; 
}

// MÉTODO DA MULTIPLICAÇÃO
int chaveMultiplicacao(int chave, int tamanho){
    float A = 0.6180339887; // constante: 0 < A < 1
    float val = chave * A;
    val = val - (int) val; // sobra somente a parte fracionária

    return (int) (tamanho * val); // retorna a parte inteira --> posição em que a chave será colocada
}

// MÉTODO DA DOBRA
int chaveDobra(int chave, int tamanho){
    int num_bits = 5;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (tamanho - 1);
    return (parte1^parte2);
}

// TRATAMENTO DE COLISÃO 
int sondagemLinear(int pos, int i, int tamanho){
    return ((pos + i) & 0x7FFFFFFF) % tamanho;
}

int sondagemQuadratica(int pos, int i, int tamanho){
    pos = pos + 2*i + 5*i*i;
    return (pos & 0x7FFFFFFF) % tamanho;
}

int duploHash(int H1, int chave, int i, int tamanho){
    int H2 = chaveDivisao(chave, tamanho-1) + 1;
    return ((H1 + i*H2) && 0x7FFFFFFF) % tamanho;
}