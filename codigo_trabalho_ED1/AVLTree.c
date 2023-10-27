#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLTree.h"
#include "ListaDinEncad.h"

// função que retorna a altura de um nó (recebe o ponteiro do nó como parâmetro)
int alt_NO(struct NO *no){
    if(no==NULL)
        return -1;
    else
        return no->alt;
}

// função que retorna a altura de uma árvore (recebe o ponteiro da árvore como parâmetro)
int altura_ArvAVL(ArvAVL *raiz){
    if(raiz==NULL)
        return 0;
    if(*raiz==NULL)
        return 0;
    int alt_esq=altura_ArvAVL(&((*raiz)->esq));
    int alt_dir=altura_ArvAVL(&((*raiz)->dir));
    if(alt_esq>alt_dir)
        return (alt_esq+1);
    else
        return (alt_dir+1);
}

// função que retorna um struct telefone (recebe o numero, ponteiro para nome e endereço, que inicializarão a struct, como parâmetros)
struct telefone *cria_telefone(int numero1, char *nome1, char *endereco1){
    struct telefone *telefone = (struct telefone*) malloc(sizeof(struct telefone));
    if(telefone==NULL)
        return NULL;
    telefone->numero=numero1;
    telefone->endereco=strdup(endereco1);
    telefone->nome=strdup(nome1);
    return telefone;
}

// função que cria uma árvore AVL (recebe como parâmetro o DDD)
ArvAVL *cria_AVL(int DDD) {
    ArvAVL *raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if (raiz != NULL) {
        *raiz = (struct NO*) malloc(sizeof(struct NO));
        if (*raiz != NULL) {
            struct telefone *telefone = cria_telefone(0,"","");
            (*raiz)->DDD = DDD;
            (*raiz)->info = (*telefone);
            (*raiz)->alt = 0;
            (*raiz)->esq = NULL;
            (*raiz)->dir = NULL;
        } else {
            free(raiz);
            raiz = NULL;
        }
    }
    return raiz;
}

// função que libera um no (recebe como parâmetro um ponteiro para o ponteiro do no)
void libera_NO(struct NO** no) {
    if (*no == NULL)
        return;
    libera_NO(&(*no)->esq);
    libera_NO(&(*no)->dir);
    free(*no);
    *no = NULL;
}

// função que libera uma árvore AVL 
void libera_ArvAVL(ArvAVL* raiz) {
    if (raiz == NULL)
        return;
    libera_NO(raiz);
    free(raiz);
}

// função que calcula o fator de balanceamento de um nó
int fatorBalanceamento_NO(struct NO *no){
    return labs(alt_NO(no->esq)-alt_NO(no->dir));
}

// função que calcula o maior entre dois numeros (recebe os numeros como parametros)
int maior(int x, int y){
    if(x>y)
        return x;
    else
        return y;
}

// função que rotaciona uma arvore avl para a direita
void rotacaoLL(ArvAVL *raiz){
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir=*raiz;
    (*raiz)->alt=maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    no->alt= maior(alt_NO(no->esq), (*raiz)->alt) +1;
    *raiz = no;
}

// função que rotaciona uma arvore avl para a esquerda
void rotacaoRR(ArvAVL *raiz){
    struct NO *no;
    no=(*raiz)->dir;
    (*raiz)->dir=no->esq;
    no->esq=(*raiz);
    (*raiz)->alt=maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) +1;
    no->alt = maior(alt_NO(no->dir), (*raiz)->alt) +1;
    (*raiz) = no;
}

// função que rotaciona uma arvore avl, primeiro para esquerda e depois para a direita
void rotacaoLR(ArvAVL *A){
    rotacaoRR(&(*A)->esq);
    rotacaoLL(A);
}

// função que rotaciona uma arvore avl, primeiro para direita e depois para a esquerda
void rotacaoRL(ArvAVL *A){
    rotacaoLL(&(*A)->dir);
    rotacaoRR(A);
}

// função que percorre uma árvore AVL em pré-ordem e insere os elementos encontrados em uma lista encadeada
void preOrdem_ArvAVL_inserir(ArvAVL *raiz, Lista *li){
    if(raiz==NULL)
        return;
    if(*raiz!=NULL){
        insere_lista_inicio(&(*li),&(*raiz)->info);
        preOrdem_ArvAVL_inserir(&((*raiz)->esq),&(*li));
        preOrdem_ArvAVL_inserir(&((*raiz)->dir),&(*li));
    }
}

// função que imprime um árvore AVL em pré-ordem
void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz==NULL)
        return;
    if(*raiz!=NULL){
        printf("%i\n", (*raiz)->info.numero);
        printf("%s\n", (*raiz)->info.nome);
        printf("%s\n", (*raiz)->info.endereco);
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

// função que imprime um árvore AVL em em-ordem
void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz==NULL)
        return;
    if(*raiz!=NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("%i\n", (*raiz)->info.numero);
        printf("%s\n", (*raiz)->info.nome);
        printf("%s\n", (*raiz)->info.endereco);
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

// função que imprime um árvore AVL em pos-ordem
void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz==NULL)
        return;
    if(*raiz!=NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%i\n", (*raiz)->info.numero);
        printf("%s\n", (*raiz)->info.nome);
        printf("%s\n", (*raiz)->info.endereco);
    }
}

// função para inserir uma struct telefone em uma árvore AVL
int insere_ArvAVL(ArvAVL* raiz, struct telefone valor) {
    if((*raiz)->info.numero==0 && (*raiz)->esq==NULL && (*raiz)->dir==NULL){ //caso em que é a raiz da árvore
        (*raiz)->info=valor;
        printf("\n\nUsuario inserido com sucesso!!\n\n");
        return 1;
    }
    if ((*raiz)==NULL||*raiz==NULL) {
        struct NO* novo = (struct NO*) malloc(sizeof(struct NO));
        if (novo == NULL)
            return 0;
        novo->DDD=(*raiz)->DDD;
        novo->info = valor;
        novo->alt = 0;
        novo->dir = NULL;
        novo->esq = NULL;
        *raiz = novo;
        printf("\n\nUsuario inserido com sucesso!!\n\n");
        return 1;
    }
    if (valor.numero < (*raiz)->info.numero) {
        if (insere_ArvAVL(&(*raiz)->esq, valor) == 1) {
            if (fatorBalanceamento_NO(*raiz) >= 2) {
                if (valor.numero < (*raiz)->esq->info.numero)
                    rotacaoLL(raiz);
                else
                    rotacaoLR(raiz);
            }
        }
    } else {
        if (valor.numero > (*raiz)->info.numero) {
            if (insere_ArvAVL(&(*raiz)->dir, valor) == 1) {
                if (fatorBalanceamento_NO(*raiz) >= 2) {
                    if ((*raiz)->dir->info.numero < valor.numero)
                        rotacaoRR(raiz);
                    else
                        rotacaoRL(raiz);
                }
            }
        } else {
            printf("Numero Duplicado!!\n");
            // Valor duplicado
            return 0;
        }
    }
    printf("\n\nUsuario inserido com sucesso!!\n\n");
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    return 1;
}

// função que procura o menor nó
struct NO* procuraMenor(struct NO* atual){
    struct NO *no1=atual,*no2=atual->esq;
    while(no2!=NULL){
        no1=no2;
        no2=no2->esq;
    }
    return no1;
}

// função que procura o maior nó
struct NO* procuraMaior(struct NO* atual){
    struct NO *no1=atual,*no2=atual->esq;
    while(no2!=NULL){
        no1=no2;
        no2=no2->dir;
    }
    return no1;
}

// função que sugere um numero maior
int sugerirNumeroMaior(struct NO* atual){
    struct NO *no1=atual,*no2=atual->esq;
    while(no2!=NULL){
        no1=no2;
        no2=no2->dir;
    }
    return no1->info.numero + 1;
}

// função que sugere um numero menor
int sugerirNumeroMenor(struct NO* atual){
    struct NO *no1=atual,*no2=atual->esq;
    while(no2!=NULL){
        no1=no2;
        no2=no2->esq;
    }
    return no1->info.numero - 1;
}

// função que remove uma struct telefone de uma árvore AVL
int remove_ArvAVL(ArvAVL *raiz, struct telefone *valor){
    printf("Altura da arvore atual antes da remocao: %i\n", altura_ArvAVL(raiz));
    if(*raiz==NULL)
        return 0;
    int res;
    if(valor->numero<(*raiz)->info.numero){
        if((res=remove_ArvAVL(&(*raiz)->esq, valor)) == 1){
            if(fatorBalanceamento_NO(*raiz)>=2){
                if(alt_NO((*raiz)->dir->esq)<=alt_NO((*raiz)->dir->dir))
                    rotacaoRR(raiz);
                else
                    rotacaoRL(raiz);
            }
        }
    }
    if((*raiz)->info.numero<valor->numero){
        if((res=remove_ArvAVL(&(*raiz)->dir,valor))==1){
            if(fatorBalanceamento_NO(*raiz) >=2){
                if(alt_NO((*raiz)->esq->dir)<=alt_NO((*raiz)->esq->esq))
                    rotacaoLL(raiz);
                else
                    rotacaoLR(raiz);
            }
        }
    }
    if((*raiz)->info.numero==valor->numero){
        if(((*raiz)->esq==NULL || (*raiz)->dir==NULL)){ //no tem um filho ou nenhum
            struct NO *oldNode = (*raiz);
            if((*raiz)->esq!=NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz=(*raiz)->dir;
            free(oldNode);
        }
        else{ //nó tem dois filhos
            struct NO *temp = procuraMenor((*raiz)->dir);
            (*raiz)->info=temp->info;
            remove_ArvAVL(&(*raiz)->dir,&(*raiz)->info);
            if(fatorBalanceamento_NO(*raiz)>=2){
                if(alt_NO((*raiz)->esq->dir)<=alt_NO((*raiz)->esq->esq))
                    rotacaoLL(raiz);
                else
                    rotacaoLR(raiz);
            }
        }
        if(*raiz!=NULL)
            (*raiz)->alt=maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    printf("Altura da arvore atual apos a remocao: %i\n", altura_ArvAVL(raiz));
    return 1;
    }
    (*raiz)->alt=maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    return res;
}

// função que procura um telefone a partir do nome e retorna o telefone
struct telefone* procura_nome(ArvAVL *raiz, char *nome1){
        if (raiz == NULL) {
        printf("A arvore esta vazia.\n");
        return NULL;
    }

    struct NO* pilha[100];  // Tamanho máximo da pilha
    int topo = -1;

    struct NO* atual = *raiz;

    while (atual != NULL || topo != -1) {
        // Percorre até o nó mais à esquerda da árvore e empilha todos os nós ao longo do caminho
        while (atual != NULL) {
            if(strcmp(atual->info.nome,nome1)==0){
                return &(atual->info);
            }
            pilha[++topo] = atual;
            atual = atual->esq;
        }

        // Nesse ponto, chegamos ao nó mais à esquerda, então o visitamos
        atual = pilha[topo--];

        // Agora, passamos para o nó à direita do nó atual
        atual = atual->dir;
    }
    return NULL;
}

// função que remove um telefone a partir do nome 
int removeTelefoneNome(ArvAVL *raiz, char *nome1){
    int res = 0;
    if(procura_nome(raiz,nome1)!=NULL){
        res = remove_ArvAVL(raiz,procura_nome(raiz,nome1));
    }
    return res;
}

// função que procura um telefone a partir do numero e retorna o telefone
struct telefone *procurar_telefone(ArvAVL *raiz, int numero){
    if(raiz==NULL)
        return NULL;
    struct NO* atual = *raiz;
    while(atual!=NULL){
        if(numero==atual->info.numero){
            struct telefone *celular = &(atual->info);
            return celular;//achou
        }
        if(numero>atual->info.numero)
            atual=atual->dir;
        else
            atual = atual->esq;
    }
    return NULL;//nao achou
}

// função que imprime por ordem de número de telefone os usuarios de um DDD
void ListaEmNumeroCrescente(ArvAVL *raiz){
    if(raiz==NULL)
        return;
    if(*raiz!=NULL){
        ListaEmNumeroCrescente(&((*raiz)->esq));
        printf("Nome: %s\n", (*raiz)->info.nome);
        printf("Endereco: %s\n", (*raiz)->info.endereco);
        printf("Numero: %i\n", (*raiz)->info.numero);
        ListaEmNumeroCrescente(&((*raiz)->dir));
    }
}

// função que imprime por ordem alfabética os usuarios de um DDD
void ListaEmOrdemAlfabetica(ArvAVL *raiz){
    if(raiz==NULL)
        return;
    if(*raiz!=NULL){
        Lista *li = cria_lista();
        preOrdem_ArvAVL_inserir(&(*raiz),&(*li));
        ordernarLista(li);
        ElemLista *no = (*li);
        struct telefone *telefone_ordenado= &no->dados;
        while(telefone_ordenado!=NULL){
            printf("Nome: %s\n", telefone_ordenado->nome);
            printf("Endereco: %s\n", telefone_ordenado->endereco);
            printf("Numero: %i\n", telefone_ordenado->numero);
            no=no->prox;
            telefone_ordenado=&no->dados;
        }
        libera_lista(li);
    }
    return;
}

// função que retorna o número mais próximo do número buscado
void buscaAproximada(ArvAVL *raiz, int numeroMenor){
    if(raiz==NULL)
        return;
    if(*raiz!=NULL){
        int num = (*raiz)->info.numero;
        char strNum[9];
        sprintf(strNum, "%d", num);
        char numMenor[9];
        sprintf(numMenor, "%d", numeroMenor);
        char *parte = strstr(strNum,numMenor);
        if(parte!=NULL){
            printf("Numero achado pela sua pesquisa\n");
            printf("Numero: %i\n", (*raiz)->info.numero);
        }
        buscaAproximada(&((*raiz)->esq),numeroMenor);
        buscaAproximada(&((*raiz)->dir),numeroMenor);
    }
}

// função que verifica se um nome já está cadastrado em um DDD (árvore)
int verificaNome(ArvAVL *raiz, struct telefone *valor) {
    if (raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int res;
    if (*raiz != NULL) {
        //printf("Comparando: %s com %s\n", (*raiz)->info.nome, valor->nome);
        //printf("%s%s",(*raiz)->info.nome, valor->nome);
        int iguais = strcmp((*raiz)->info.nome,valor->nome);
        if (iguais == 0) {
            return 1;
        }
        if((*raiz)->esq!=NULL){
        res = verificaNome(&((*raiz)->esq), valor);
        if (res == 1)
            return 1;
        }
        if((*raiz)->dir!=NULL){
        res = verificaNome(&((*raiz)->dir), valor);
        if (res == 1)
            return 1;
        }
    }
    
    return 0;
}

// função que insere um struct telefone em uma árvore AVL checando se já existe um usuário com esse nome
int inserir_checando_nome(ArvAVL *raiz, struct telefone *valor){
    int verificador = verificaNome(&(*raiz), &(*valor));
    if(verificador==0){
        int resultado = insere_ArvAVL(raiz,(*valor));
        return resultado;
    }
    else{
        printf("\n\nNome Duplicado.\n\n");
        return 0;
    }
}