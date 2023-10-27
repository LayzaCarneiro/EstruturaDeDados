struct aluno{
    int matricula;
    char nome[30];
};

typedef struct hash Hash;

Hash* criaHash(int tamanho);
void liberaHash(Hash* ha);
int chaveDivisao(int chave, int tamanho);
int insereAluno(Hash *ha, struct aluno al);
int buscaAluno(Hash *ha, int mat, struct aluno al);
int removeAluno(Hash *ha, struct aluno al);
int mediaAluno(Hash *ha);