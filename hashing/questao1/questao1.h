#define TABLE_SIZE 100

struct elemento{
    char nome[30];
    struct elemento *prox;
};

typedef struct{
    int qtd, tam;
    struct elemento **itens;
} Hash;

Hash* criaHash(int tamanho);
void liberaHash(Hash* ha);
int chaveDivisao(int chave, int tamanho);
int insereCidade(Hash* ha, struct elemento ci);
void imprimeColisao(Hash* ha);