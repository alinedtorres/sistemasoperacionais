#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "algoritmos.h"
#include "memoria.h"
#include "tabela_pag.h"

#define MIN_PARAM 5
#define TAM_STRING 20


int main(int argc, char *argv[]){
    char algoritmo[TAM_STRING];
    FILE *arq_entrada;
    int tam_pagina, tam_memoria, modo;
    int bits_ignorar, num_blocos;
    unsigned addr;
    char rw;
    long int ender_page, tam_tabela;
    int indice = 0, tempo = 0, aux = 0;
    memoria m;
    int* tabela_paginas;
    int paginas_sujas = 0;
    int page_faults = 0;
    int aux_sujas = 0;

    //Recebendo parâmetros
    if(argc >= MIN_PARAM){
        strcpy(algoritmo, argv[1]);
        arq_entrada = fopen(argv[2], "r");

        if (arq_entrada == NULL){
            printf("\nProblemas na leitura do arquivo!\n");
            exit(-1);
        }
        tam_pagina = (int) atoi(argv[3]);
        tam_memoria = (int) atoi(argv[4]);
        if(argc > MIN_PARAM){
            modo = (int) atoi(argv[5]);
        }
    } else {
        printf("\nErro! Estao faltando parametros.\n");
        exit(-1);
    }

    //Checando algoritmo escolhido
    if((strcmp(algoritmo, "lru") != 0) && (strcmp(algoritmo, "fifo") != 0) && (strcmp(algoritmo, "random") != 0) && (strcmp(algoritmo, "2a") != 0)){
        printf("\nAlgoritmo nao existe. Utilize 'lru', 'fifo', 'random' ou '2a' para escolher o algoritmo.");
        exit(-1);
    }
    
    //Prepara memória física
    num_blocos = tam_memoria/tam_pagina;
    memoria_vazia(&m, num_blocos);

    //Prepara tabela de páginas
    bits_ignorar = calc_bits_menos_signf(tam_pagina);
    aux = 32 - bits_ignorar;
    tam_tabela = pow(2, aux);
    tabela_vazia(&tabela_paginas, tam_tabela);

    printf("\nbits: %d tabela: %ld memoria: %d\n", bits_ignorar, tam_tabela, num_blocos);
    printf("\nExecutando o simulador...");

    aux = 0;
    indice = 0;
    tempo = 0;

    while (fscanf(arq_entrada,"%X %c",&addr,&rw) != EOF) {
        ender_page = addr >> bits_ignorar;
        aux = verificar_memoria(tabela_paginas, ender_page, indice, rw, tempo, m, num_blocos);
        aux_sujas = 0;
        if(rw == 'W'){
            paginas_sujas++;
        }
        if(aux == -2){
            if(strcmp(algoritmo, "fifo") == 0){
                aux_sujas = algoritmos_reposicao(tabela_paginas, ender_page, rw, tempo, m, num_blocos, 0);

            } else if(strcmp(algoritmo, "lru") == 0){
                aux_sujas = algoritmos_reposicao(tabela_paginas, ender_page, rw, tempo, m, num_blocos, 1);

            } else if(strcmp(algoritmo, "random") == 0){
                aux_sujas = algoritmos_reposicao(tabela_paginas, ender_page, rw, tempo, m, num_blocos, 2);

            } else if(strcmp(algoritmo, "2a") == 0){
                aux_sujas = algoritmos_reposicao(tabela_paginas, ender_page, rw, tempo, m, num_blocos, 3);

            }
            page_faults++;
        } else if(aux == 0){
            indice++;
            page_faults++;
        }
        tempo++;        
            paginas_sujas = paginas_sujas + aux_sujas;
    }
    
    printf("\n---------------------------------------------");
    printf("\nDados da simulacao:");
    printf("\n\tArquivo de entrada: %d", 10);
    printf("\n\tTamanho da memoria: %d KB", tam_memoria);
    printf("\n\tTamanho das paginas: %d KB", tam_pagina);
    printf("\n\tAlgoritmo de reposicao: %s", algoritmo);
    printf("\n\nResultados:");
    printf("\n\tPaginas lidas: %d", page_faults);
    printf("\n\tPaginas escritas: %d", paginas_sujas);
    printf("\n---------------------------------------------\n");

    free(m);
    free(tabela_paginas);
    fclose(arq_entrada);
    return 0;
}