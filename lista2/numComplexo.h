typedef struct complexo Complexo;
// z = x + iy --> i = -1

Complexo* criarNumComplexo(int x, int y);
void destruirNumComplexo(Complexo* complexo);
void somaNumComplexo(Complexo* complexo1, Complexo* complexo2);
void multNumComplexo(Complexo* complexo1, Complexo* complexo2);