#include <stdlib.h>
#include <stdio.h>
#include "esfera.h"

struct esfera{
    float raio;
};

Esfera* criarEsfera(float raio){
    Esfera* esfera = (Esfera*) malloc(sizeof(Esfera));
    if(esfera == NULL) exit(1);
    esfera->raio = raio;
    return esfera;
};
void destruirEsfera(Esfera* esfera){
    free(esfera);
};
float raio(Esfera* esfera){
    return esfera->raio;
};
float area(Esfera* esfera){
    return (4*esfera->raio*esfera->raio*3.14);
};
float volume(Esfera* esfera){
    return (4*esfera->raio*esfera->raio*esfera->raio*3.14)/3;
};

int main(){
    Esfera* esfera = criarEsfera(3);
    printf("Raio: %f\n", raio(esfera));
    printf("Área: %f\n", area(esfera));
    printf("Volume: %f\n", volume(esfera));

    return 0;
}