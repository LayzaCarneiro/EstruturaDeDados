struct procura{
    int valor;
};

typedef struct hash Hash;

int insereHash_EnderAberto(Hash *ha, struct procura p);
int buscaHash_EnderAberto(Hash *ha, int x, struct procura p);
int chaveDivisao(int chave, int tamanho);
int sondagemLinear(int pos, int i, int tamanho);
int sondagemQuadratica(int pos, int i, int tamanho);
int duploHash(int H1, int chave, int i, int tamanho);