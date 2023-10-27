struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct hash Hash;

Hash* criaHash(int tamanho);
void liberaHash(Hash* ha);
int chaveDivisao(int chave, int tamanho);
int valorString(char *str);
int insereHash_SemColisao(Hash *ha, struct aluno al);
int buscaHash_SemColisao(Hash *ha, int mat, struct aluno al);
int insereHash_EnderAberto(Hash *ha, struct aluno al);
int buscaHash_EnderAberto(Hash *ha, int mat, struct aluno al);
int chaveDivisao(int chave, int tamanho);