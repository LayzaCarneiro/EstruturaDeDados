#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TabelaHash.h"
#include "AVLTree.h"
#include "ListaDinEncad.h"

int main(){
    Hash *tabela = cria_hash(1000); // cria a tabela hash 
    int entrada;

    do{
        printf("\n>>>>> Sistema de catalogo nacional de telefones e enderecos <<<<<\n");
        printf("\nOPERACOES POSSIVEIS: \n");
        printf("1. Inserir um usuario;\n");
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
            clock_t inicio, final;
            double tempo_execucao;

            int DDD, numero, opc;
            char nome[100], endereco[100];
            
            printf("\nInforme o DDD: ");
            scanf("%d", &DDD);
            printf("Informe o numero de telefone: ");
            scanf("%d", &numero);
            getchar(); 
            printf("Informe o nome: ");
            scanf(" %[^\n]", nome);
            printf("Informe o endereco: ");
            scanf(" %[^\n]", endereco);

            inicio = clock(); // marca o inicio da contagem do tempo da função de inserir 

            if(buscaHash_EncSep(tabela, DDD) == NULL){ // confere se já existe um árvore com esse DDD na tabela hash
                ArvAVL *raiz1 = cria_AVL(DDD); // caso não exista, cria essa árvore
                if(raiz1 != NULL)
                    insereHash_EncSep(tabela, raiz1); // se árvore for criada, insere ela na tabela
            }

            ArvAVL *raiz2 = buscaHash_EncSep(tabela, DDD);  // pega a árvore que existe na tabela hash com esse DDD
            struct telefone *telefone = cria_telefone(numero, nome, endereco); // cria o struct telefone com os valores fornecidos pelo usuário
            if(raiz2!=NULL && telefone!=NULL) // se a árvore buscada e o struct criado existirem
                inserir_checando_nome(raiz2, telefone); // insere esse telefone na árvore desejada, conferindo se já existe usuário cadastrado com esse nome

            final = clock(); // marca o fim da contagem do tempo da função de inserir
            tempo_execucao = ((double) (final - inicio)) / CLOCKS_PER_SEC; // Calcular tempo de execução
            printf("Tempo de execucao da insercao: %f segundos\n", tempo_execucao);
            printf("\nDeseja continuar usando o catalogo? [1] Sim  [2] Nao  >>>  ");
            scanf("%d", &opc);
            if(opc==2){
                printf("Ate mais!!! ;)");
                exit(1);
            }
        }

        else if(entrada==2){
            int numero, ddd, opc;
            
            printf("\nInforme o DDD do numero: ");
            scanf("%d", &ddd);
            printf("Informe o numero para consulta: ");
            scanf("%d", &numero);

            clock_t inicio, final;
            double tempo_execucao;
            inicio = clock(); // marca o inicio da contagem do tempo da função de buscar 

            ArvAVL *raiz = buscaHash_EncSep(tabela, ddd); // pega a árvore que existe na tabela hash com o DDD fornecido pelo usuário
            if(raiz != NULL){
                struct telefone *tel = procurar_telefone(raiz, numero); // pega o telefone que existe na árvore com o número desejado e imprime o nome e endereço dele
                printf("Nome: %s\n", tel->nome);
                printf("Endereco: %s\n", tel->endereco);
            }

            final = clock(); // marca o final da contagem do tempo da função de buscar 
            tempo_execucao = ((double) (final - inicio)) / CLOCKS_PER_SEC; // Calcular tempo de execução
            printf("\nTempo de execucao da busca: %f segundos\n", tempo_execucao);
            printf("\nDeseja continuar usando o catalogo? [1] Sim  [2] Nao  >>>  ");
            scanf("%d", &opc);
            if(opc==2){
                printf("Ate mais!!! ;)");
                exit(1);
            }
        }

        else if(entrada==3){
            char nome[100];
            int ddd, opc;
            
            printf("\nInforme o nome do usuario que sera descadastrado: ");
            scanf(" %[^\n]", nome);
            printf("Informe o DDD do usuario: ");
            scanf("%d", &ddd);

            clock_t inicio, final;
            double tempo_execucao;
            inicio = clock(); // marca o inicio da contagem do tempo da função de remover 

            ArvAVL *raiz = buscaHash_EncSep(tabela, ddd); // pega a árvore que existe na tabela hash com o DDD fornecido pelo usuário
            struct telefone *telefone = cria_telefone(997335674,"italo","rua 7");
            int x = remove_ArvAVL(raiz, telefone); // remove o telefone da árvore
            
            final = clock(); // marca o final da contagem do tempo da função de remover 
            tempo_execucao = ((double) (final - inicio)) / CLOCKS_PER_SEC; // Calcular tempo de execução
            printf("\nTempo de execucao da remocao: %f segundos\n", tempo_execucao);
            printf("\nDeseja continuar usando o catalogo? [1] Sim  [2] Nao  >>>  ");
            scanf("%d", &opc);
            if(opc==2){
                printf("Ate mais!!! ;)");
                exit(1);
            }
        }

        else if(entrada==4){
            int ddd, opc;

            printf("\nInforme o DDD desejado: ");
            scanf("%d", &ddd);

            clock_t inicio, final;
            double tempo_execucao;
            inicio = clock();  // marca o inicio da contagem do tempo da função de sugestao de numero 

            ArvAVL *raiz = buscaHash_EncSep(tabela, ddd); // pega a árvore que existe na tabela hash com o DDD fornecido pelo usuário
            if(raiz != NULL){
                int num1 = sugerirNumeroMaior(*raiz); // sugere um numero maior
                printf("%i\n", num1);
                int num2 = sugerirNumeroMenor(*raiz); // sugere um numero menor
                printf("%i\n", num2);
                int num3 = sugerirNumeroMaior(*raiz) + 1; // sugere um terceiro numero
                printf("%i\n", num3);
            }

            final = clock();  // marca o final da contagem do tempo da função de sugestao de numero 
            tempo_execucao = ((double) (final - inicio)) / CLOCKS_PER_SEC; // Calcular tempo de execução
            printf("\nTempo de execucao da remocao: %f segundos\n", tempo_execucao);
            printf("\nDeseja continuar usando o catalogo? [1] Sim  [2] Nao  >>>  ");
            scanf("%d", &opc);
            if(opc==2){
                printf("Ate mais!!! ;)");
                exit(1);
            }
        }

        else if(entrada==5){
            int ddd, opcao, opc;

            printf("\nInforme o formato a ser ordenado: \n");
            printf("[1] Pre-ordem;\n");
            printf("[2] Em-ordem;\n");
            printf("[3] Pos-ordem;\n");
            printf("\nopcao >>>>  ");
            scanf("%d", &opcao);
            
            printf("\nInforme o DDD da lista a ser ordenada: ");
            scanf("%d", &ddd);

            clock_t inicio, final; 
            double tempo_execucao;
            inicio = clock(); // marca o inicio da contagem do tempo da função de busca ordenada 

            ArvAVL *raiz = buscaHash_EncSep(tabela, ddd); // pega a árvore que existe na tabela hash com o DDD fornecido pelo usuário
            if(raiz!=NULL){
                if(opcao==1)
                    preOrdem_ArvAVL(raiz); // imprime a árvore em pré-ordem
                else if(opcao==2)
                    emOrdem_ArvAVL(raiz); // imprime a árvore em em-ordem
                else if(opcao==3)
                    posOrdem_ArvAVL(raiz); // imprime a árvore em pós-ordem
            }

            final = clock(); // marca o fim da contagem do tempo da função de busca ordenada
            tempo_execucao = ((double) (final - inicio)) / CLOCKS_PER_SEC; // Calcular tempo de execução
            printf("\nTempo de execucao da remocao: %f segundos\n", tempo_execucao);
            printf("\nDeseja continuar usando o catalogo? [1] Sim  [2] Nao  >>>  ");
            scanf("%d", &opc);
            if(opc==2){
                printf("Ate mais!!! ;)");
                exit(1);
            }
        }

        else if(entrada==6){
            int ddd, opcao, opc;

            printf("\nInforme o formato a ser ordenado: \n");
            printf("[1] Por numero de telefone;\n");
            printf("[2] Por nome de usuario;\n");
            printf("\nopcao >>>>  ");
            scanf("%d", &opcao);

            printf("Informe o DDD da lista a ser ordenada: ");
            scanf("%d", &ddd);

            clock_t inicio, final;
            double tempo_execucao;
            inicio = clock(); // marca o inicio da contagem do tempo da função de busca ordenada

            ArvAVL *raiz = buscaHash_EncSep(tabela, ddd); // pega a árvore que existe na tabela hash com o DDD fornecido pelo usuário

            if(opcao == 1)
                ListaEmNumeroCrescente(raiz); // imprime os usuarios por ordem de número de telefone
            else if(opcao == 2)
                ListaEmOrdemAlfabetica(raiz); // imprime os usuarios por ordem alfabética

            final = clock(); // marca o fim da contagem do tempo da função de busca ordenada
            tempo_execucao = ((double) (final - inicio)) / CLOCKS_PER_SEC; // Calcular tempo de execução
            printf("\nTempo de execucao da remocao: %f segundos\n", tempo_execucao);
            printf("\nDeseja continuar usando o catalogo? [1] Sim  [2] Nao  >>>  ");
            scanf("%d", &opc);
            if(opc==2){
                printf("Ate mais!!! ;)");
                exit(1);
            }
        }

        else if(entrada == 7){
            int ddd, numero, opc;

            printf("\nInforme o DDD do numero desejado: ");
            scanf("%d", &ddd);
            printf("Informe o numero a ser buscado: ");
            scanf("%d", &numero);

            clock_t inicio, final;
            double tempo_execucao;
            inicio = clock(); // marca o inicio da contagem do tempo da função de busca 

            ArvAVL *raiz = buscaHash_EncSep(tabela, ddd); // pega a árvore que existe na tabela hash com o DDD fornecido pelo usuário
            buscaAproximada(raiz, numero); // busca o número cadastrado mais próximo ao número fornecido, e imprime

            final = clock(); // marca o fim da contagem do tempo da função de busca 
            tempo_execucao = ((double) (final - inicio)) / CLOCKS_PER_SEC; // Calcular tempo de execução
            printf("\nTempo de execucao da remocao: %f segundos\n", tempo_execucao);
            printf("\nDeseja continuar usando o catalogo? [1] Sim  [2] Nao  >>>  ");
            scanf("%d", &opc);
            if(opc==2){
                printf("Ate mais!!! ;)");
                exit(1);
            }
        }
    } while (entrada != 0); 

    printf("Ate mais!!! ;)");
    printf("                                                                                                                             projeto por: italo, layza, vinicius, malu.");

    liberaHash(tabela); // libera a tabela hash criada

    return 0;
};
