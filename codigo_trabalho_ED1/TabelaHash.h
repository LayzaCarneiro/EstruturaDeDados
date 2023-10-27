#ifndef TABELAHASH_H
#define TABELAHASH_H
#include "AVLTree.h"

struct elemento{
    ArvAVL raiz;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct hash{
    int qnt, TABLE_SIZE;
    Elem **cis;
};
typedef struct hash Hash;

Hash *cria_hash(int tamanho);
void liberaHash(Hash *hash);
int valor(int key, int tableSize);
int insereHash_EncSep(Hash *ha, ArvAVL *raiz1);
ArvAVL *buscaHash_EncSep(Hash *ha, int DDD); //procura a raiz com o DDD, se achar retorna a raiz
int removeDoHash(Hash *ha, ArvAVL *raiz);
#endif