#include <stdlib.h>
#include <stdio.h>
#include "numComplexo.h"

struct complexo {
    int x;
    int y;
};

Complexo* criarNumComplexo(int x, int y){
    Complexo* complexo = (Complexo*) malloc(sizeof(Complexo));
    if(complexo == NULL) exit(1);
    complexo->x = x;
    complexo->y = y;
    return complexo;
};
void destruirNumComplexo(Complexo* complexo){
    free(complexo);
};
void somaNumComplexo(Complexo* complexo1, Complexo* complexo2){
    Complexo* resultado = criarNumComplexo(0, 0);
    if(resultado == NULL) exit(1);
    resultado->x = complexo1->x + complexo2->x;
    resultado->y = complexo1->y + complexo2->y;
    printf("Resultado da soma: %i + %ii\n", resultado->x, resultado->y);
};
void multNumComplexo(Complexo* complexo1, Complexo* complexo2){
    Complexo* resultado = criarNumComplexo(0, 0);
    resultado->x = (complexo1->x * complexo2->x) - (complexo1->y * complexo2->y);
    resultado->y = (complexo1->x * complexo2->y) + (complexo1->y * complexo2->x);
    printf("Resultado da multiplicacao: %i + %ii\n", resultado->x, resultado->y);
};

int main(){
    Complexo* complexo1 = criarNumComplexo(6, 5);
    Complexo* complexo2 = criarNumComplexo(2, -1);

    somaNumComplexo(complexo1, complexo2);
    multNumComplexo(complexo1, complexo2);

    destruirNumComplexo(complexo1);
    destruirNumComplexo(complexo2);

    return 0;
}