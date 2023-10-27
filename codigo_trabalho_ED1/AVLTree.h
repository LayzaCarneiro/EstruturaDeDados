#ifndef AVLTREE_H
#define AVLTREE_H

typedef struct NO *ArvAVL;
struct telefone{
    int numero;//sem DDD
    char *nome;
    char *endereco;
};
struct NO{
    int DDD;
    struct telefone info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

ArvAVL *cria_AVL(int DDD);
int insere_ArvAVL(ArvAVL *raiz, struct telefone valor);
int remove_ArvAVL(ArvAVL *raiz, struct telefone *valor);
struct telefone* procura_nome(ArvAVL *raiz, char *nome1);
struct telefone *procurar_telefone(ArvAVL *raiz, int numero); //retorna o telefone a partir e um numero e uma raiz passada como parametro, voce pode usar para achar nome e endereco da pessoa
struct telefone *cria_telefone(int numero1, char *nome1, char *endereco1);
int inserir_checando_nome(ArvAVL *raiz, struct telefone *valor);
int removeTelefoneNome(ArvAVL *raiz, char *nome1);
int verificaNome(ArvAVL *raiz, struct telefone *valor);
int sugerirNumeroMaior(struct NO* atual);
int sugerirNumeroMenor(struct NO* atual);
int alt_NO(struct NO *no);
int altura_ArvAVL(ArvAVL *raiz);
void libera_NO(struct NO** no);
void libera_ArvAVL(ArvAVL *raiz);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);
void ListaEmNumeroCrescente(ArvAVL *raiz);
void ListaEmOrdemAlfabetica(ArvAVL *raiz);
void buscaAproximada(ArvAVL *raiz, int numeroMenor);

#endif