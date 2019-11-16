#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <tads.h>
#include "algoritmos.c"

#define MIN_PARAM 5
#define TAM_STRING 20


int main(int argc, char *argv[]){
    char algoritmo[TAM_STRING], arq[TAM_STRING];
    int tam_pagina, tam_memoria, num_pagina, modo, qtd_pgs;
    int bits_ignorar;
    FILE *arq_entrada;
    printf("Iniciei");
    unsigned addr;
    char rw;
    long ender_page;


    //Recebendo parâmetros
    if(argc >= MIN_PARAM){
        printf("Passei por aqui");
        strcpy(algoritmo, argv[1]);
         //strcpy(arq, argv[2]);
        arq_entrada = fopen(argv[2], "r");

        if (arq_entrada == NULL){
            printf("Problemas na leitura do arquivo \n");
            return -1;
        }
        tam_pagina = (int) atoi(argv[3]);
        tam_memoria = (int) atoi(argv[4]);
        if(argc > MIN_PARAM){
            modo = (int) atoi(argv[5]);
        }
    } else {
        printf("\nErro! Estao faltando parametros.\n");
        return -1;
    }

    bits_ignorar = calc_bits_menos_signf(tam_pagina);
    qtd_pgs = tam_memoria/tam_pagina;

    printf("\n\n%s %s %d %d bits: %d", algoritmo, arq, tam_pagina, tam_memoria, bits_ignorar);

    //Escolhendo algoritmo
    if(strcmp(algoritmo, "lru") == 0){
        printf("\nlru");
    } else if(strcmp(algoritmo, "fifo") == 0){
        printf("\nfifo");
    } else if(strcmp(algoritmo, "random") == 0){
        printf("\nrandom");
    } else if(strcmp(algoritmo, "2a") == 0){
        printf("\n2a");
    } else {
            printf("\nAlgoritmo nao existe. Utilize 'lru', 'fifo', 'random' ou '2a' para escolher o algoritmo.");
            return -1;
    }


    while (fscanf(arq_entrada,"%x %c",&addr,&rw) != EOF) {
        ender_page = addr >> bits_ignorar;
       // printf("\nendereco %ld", ender_page);
   }

    return 0;
}