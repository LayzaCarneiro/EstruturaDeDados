#include <stdio.h>
#include "ponto.h"

int main(){
  Ponto* p = cria(2.0, 3.0);
  Ponto* q = cria(4.0, 5.0);

  printf("Coordenadas do ponto p: \n");
  acessa(p);
  printf("Coordenadas do ponto q: \n");
  acessa(q);

  printf("Distância entre os pontos p e q: %.2f\n", distancia(p, q));

  atribui(p, 1, 6);
  printf("Novas coordenadas do ponto p: \n");
  acessa(p);

  libera(p);
  libera(q);

  return 0;
}


