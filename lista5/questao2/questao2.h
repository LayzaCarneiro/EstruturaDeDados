typedef struct No* ArvBin;

struct No{
    int id, ano;
    char autor[50], titulo[50];
    struct No* esq;
    struct No* dir;
};

ArvBin* cria_ArvBin();
int insere_ArvBin(ArvBin* raiz, int id, int ano, char autor[], char titulo[]);
void encontrarLivros(ArvBin* raiz, char nome[], int anoInicial, int anoFinal);