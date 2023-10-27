typedef struct ponto Ponto;

Ponto* cria(float x, float y);
void libera(Ponto* p);
int acessa(Ponto* p);
void atribui(Ponto* p, float x, float y);
float distancia(Ponto* p1, Ponto* p2);
int somaPontos(Ponto* p, Ponto* q);
int subtracaoPonto(Ponto* p, Ponto* q);