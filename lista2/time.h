typedef struct time Time;
typedef struct jogador Jogador;

Time* atribuir(char nome[], Jogador* jogadores[], int vitorias, int empates, int derrotas);
void imprimir(Time* time);
void pontuacao(Time* time); 