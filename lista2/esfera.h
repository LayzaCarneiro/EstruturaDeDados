typedef struct esfera Esfera;

Esfera* criarEsfera(float raio);
void destruirEsfera(Esfera* esfera);
float raio(Esfera* esfera);
float area(Esfera* esfera);
float volume(Esfera* esfera);