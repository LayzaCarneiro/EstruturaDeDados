typedef struct elemento Elemento;
typedef struct lista Lista;

Lista* cria_lista();
int inserir_elemento(Lista* lista, int dado);
int remove_elemento(Lista* lista, int valor);