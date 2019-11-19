#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "memoria.h"
#include "tabela_pag.h"
#include "algoritmos.h"


int calc_bits_menos_signf(int tam_pagina){
    int tamanho = tam_pagina, bits = 0;
    tamanho *= KB;
    while(tamanho > 1){
        tamanho = tamanho >> 1;
        bits++;
    }
    return bits;
}

int algoritmos_reposicao(int* tabela_paginas, long int ender, char rw, long int tempo, memoria m, int tam_memoria, int escolhido){
    int indice, write = 0;
    if(escolhido == 0){ //0 para fifo 1 para lru 2 para random 3 para 2a
        indice = indicado_fifo(m, tam_memoria, tempo);
    } else if(escolhido == 1) {
        indice = indicado_lru(m, tam_memoria, tempo);
    } else if(escolhido == 2){
        srand(time(NULL));
        indice = rand() % tam_memoria;
    } else if(escolhido == 3) {
        indice = indicado_segunda(m, tam_memoria, tempo);
    } else {
        exit(-1);
    }
    if(m[indice].rw == 'W'){
    	write = 1;
    }
    tabela_paginas[m[indice].pagina] = -1;
    associar_memoria(indice, ender, rw, tempo, m);
    tabela_paginas[ender] = indice;
    return write;
}

int indicado_fifo(memoria m, int tam_memoria, long int tempo_atual){
    int i, ender_bloco = 0;
    long int tempo = tempo_atual;
    //Passa por todo o vetor até encontrar o menor tempo
    for(i = 0; i < tam_memoria; i++){
        if(tempo > m[i].tempo_entrada){
            tempo = m[i].tempo_entrada;
            ender_bloco = i;
        }
    }
    return ender_bloco;
}

int indicado_lru(memoria m, int tam_memoria, long int tempo_atual){
    int i, ender_bloco = 0;
    long int tempo = tempo_atual;
    //Passa por todo o vetor até encontrar o menor tempo
    for(i = 0; i < tam_memoria; i++){
        if(tempo > m[i].tempo_acesso){
            tempo = m[i].tempo_acesso;
            ender_bloco = i;
        }
    }
    return ender_bloco;
}

int indicado_segunda(memoria m, int tam_memoria, long int tempo_atual){
    int i, ender_bloco = 0;
    
    while(1){
        ender_bloco = indicado_fifo(m, tam_memoria, tempo_atual);
        if(m[ender_bloco].tempo_acesso != -1){
            m[ender_bloco].tempo_acesso = -1;
            m[ender_bloco].tempo_entrada = tempo_atual - 1;
            for(i = 0; i < tam_memoria; i++){
                if(i != ender_bloco){
                    m[i].tempo_entrada = m[i].tempo_entrada - 1;
                }
            }
        } else {
            return ender_bloco;
        }
    }
}

