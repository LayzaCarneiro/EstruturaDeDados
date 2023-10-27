struct produto{
    int codigo;
    int qtd;
    double preco;
    char nome[30];
};

typedef struct hash Hash;

Hash* criaHash(int tamanho);
void liberaHash(Hash* ha);
int chaveDivisao(int chave, int tamanho);
int inserirProduto(Hash* ha, struct produto p);
int buscarProduto(Hash* ha, int codigo);
int atualizarProduto(Hash* ha, struct produto p, double preco);
int removerProduto(Hash* ha, struct produto p);
int produtoMaisCaro(Hash* ha);