#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"
#include "AVLTree.h"
#include "ListaDinEncad.h"
#define MAX_SIZE 100

int main(){
    int entrada, tamanho;
    printf("\nInforme o tamanho desejado para a tabela hash: ");
    scanf("%d", &tamanho);

    Hash *tabela = cria_hash(tamanho);

    do{
        printf("\n*****OPERACOES POSSIVEIS*****\n");
        printf("1. Inserir um usuario: DDD, numero, nome, endereco;\n");
        printf("2. Consultar nome e endereco a partir de um numero;\n");
        printf("3. Remover um numero;\n");
        printf("4. Solicitar sugestao de numero;\n");
        printf("5. Listar todos os numeros em:\n");
        printf("    a. Pre-ordem;\n");
        printf("    b. Em-ordem;\n");
        printf("    c. Pos-ordem;\n");
        printf("6. Gerar um lista, por DDD, em ordem:\n");
        printf("    a. Por numero de telefone;\n");
        printf("    b. Por nome de usuario;\n");
        printf("7. Realizar busca aproximada;\n");
        printf("0. Sair;\n\n");
        printf("Entrada >>>  ");
        scanf("%d", &entrada);

        if(entrada==1){
            int DDD, numero;
            char nome[MAX_SIZE], endereco[MAX_SIZE];
            
            printf("\nInforme o DDD: ");
            scanf("%d", &DDD);

            printf("Informe o numero de telefone: ");
            scanf("%d", &numero);
            getchar(); // Consumir o caractere de nova linha

            printf("Informe o nome: ");
            fgets(nome, sizeof(nome), stdin);
            
            printf("Informe o endereco: ");
            fgets(endereco, sizeof(endereco), stdin);

            if(buscaHash_EncSep(tabela, DDD) == NULL){
                insereHash_EncSep(tabela, DDD);
                struct telefone *telefone = cria_telefone(numero, nome, endereco);
                if(telefone!=NULL){
                    inserir_checando_nome(buscaHash_EncSep(tabela, DDD), telefone);
                }

            }
            else{
                ArvAVL *raiz = buscaHash_EncSep(tabela, DDD); 
                struct telefone *telefone = cria_telefone(numero, nome, endereco);
                //printf("%i", (*raiz)->info.numero);
                //printf("%i",telefone->numero);
                inserir_checando_nome(raiz, telefone);
            }
        }

        else if(entrada==2){
            int numero, ddd;
            
            printf("\nInforme o DDD do numero: ");
            scanf("%d", &ddd);
            printf("Informe o numero para consulta: ");
            scanf("%d", &numero);

            ArvAVL *raiz = buscaHash_EncSep(tabela, ddd);
            if(raiz != NULL){
                struct telefone *tel = procurar_telefone(raiz, numero);
                printf("Nome: %s\n", tel->nome);
                printf("Endereco: %s\n", tel->endereco);
            }
        }

        else if(entrada==3){
            char nome[100];
            int ddd;
            
            printf("\nInforme o nome do usuario que sera descadastrado: ");
            scanf(" %[^\n]", nome);
            printf("Informe o DDD do usuario: ");
            scanf("%d", &ddd);

            ArvAVL *raiz = buscaHash_EncSep(tabela, ddd);
            struct telefone *telefone = cria_telefone(997335674,"italo","rua 7");
            int x = remove_ArvAVL(raiz, telefone);
            //int x = removeTelefoneNome(raiz, nome);

        }

        else if(entrada==4){
            int ddd;

            printf("\nInforme o DDD desejado: ");
            scanf("%d", &ddd);

            ArvAVL *raiz = buscaHash_EncSep(tabela, ddd);
            if(raiz != NULL){
                int num1 = sugerirNumeroMaior(*raiz);
                printf("%i\n", num1);
                int num2 = sugerirNumeroMenor(*raiz);
                printf("%i\n", num2);
                int num3 = sugerirNumeroMaior(*raiz) + 1;
                printf("%i\n", num3);
            }
        }

        else if(entrada==5){
            int ddd, opcao;

            printf("\nInforme o formato a ser ordenado: \n");
            printf("[1] Pre-ordem;\n");
            printf("[2] Em-ordem;\n");
            printf("[3] Pos-ordem;\n");
            printf("\nopcao >>>>  ");
            scanf("%d", &opcao);
            
            printf("\nInforme o DDD da lista a ser ordenada: ");
            scanf("%d", &ddd);

            ArvAVL *raiz = buscaHash_EncSep(tabela, ddd);
            if(raiz!=NULL){
            if(opcao==1)
                preOrdem_ArvAVL(raiz);
            else if(opcao==2)
                emOrdem_ArvAVL(raiz);
            else if(opcao==3)
                posOrdem_ArvAVL(raiz);
            }
        }

        else if(entrada==6){
            int ddd, opcao;

            printf("\nInforme o formato a ser ordenado: \n");
            printf("[1] Por numero de telefone;\n");
            printf("[2] Por nome de usuario;\n");
            printf("\nopcao >>>>  ");
            scanf("%d", &opcao);

            printf("Informe o DDD da lista a ser ordenada: ");
            scanf("%d", &ddd);

            ArvAVL *raiz = buscaHash_EncSep(tabela, ddd);

            if(opcao==1)
                ListaEmNumeroCrescente(raiz);
            else if(opcao==2)
                ListaEmOrdemAlfabetica(raiz);
        }

        else if(entrada == 7){
            int ddd, numero;

            printf("\nInforme o DDD do numero desejado: ");
            scanf("%d", &ddd);

            printf("Informe o numero a ser buscado: ");
            scanf("%d", &numero);

            ArvAVL *raiz = buscaHash_EncSep(tabela, ddd);

            buscaAproximada(raiz, numero);
        }
        /*struct telefone *telefone = cria_telefone(997335674,"italo","rua 7");
        ArvAVL *raiz3= buscaHash_EncSep(tabela,85);
        printf("%s",(*raiz3)->info.nome);
        inserir_checando_nome(raiz3,telefone);*/
    } while (entrada != 0);


    liberaHash(tabela);

    return 0;
};
