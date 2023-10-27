typedef struct hash Hash;

struct elemento{
    int valor;
};

int chaveDivisao(int chave, int tamanho);
int inserirElemento(Hash *ha, struct elemento e);
int buscarElemento(Hash *ha, struct elemento e);
int deletarElemento(Hash *ha, struct elemento e);