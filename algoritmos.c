#include <stdio.h>
#include <stdlib.h>

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

// void random_alg(int* tabela_paginas, long int ender, char rw, long int tempo, memoria m, int tam_memoria){
//     int indice = rand() % tam_memoria;
//     tabela_paginas[m[indice].pagina] = -1;
//     associar_memoria(indice, ender, rw, tempo, m);
//     tabela_paginas[ender] = indice;
// }

void algoritmos_reposicao(int* tabela_paginas, long int ender, char rw, long int tempo, memoria m, int tam_memoria, int escolhido){
    int indice;
    if(escolhido == 0){ //0 para fifo 1 para lru 2 para random 3 para 2a
        indice = indicado_fifo(m, tam_memoria, tempo);
    } else if(escolhido == 1) {
        indice = indicado_lru(m, tam_memoria, tempo);
    } else if(escolhido == 2){
        indice = rand() % tam_memoria;
    } else if(escolhido == 3) {
        indice = indicado_segunda(m, tam_memoria, tempo);
    } else {
        printf("\nValor invalido para algoritmo no metodo algoritmos_reposicao!\n");
        exit(-1);
    }
    tabela_paginas[m[indice].pagina] = -1;
    associar_memoria(indice, ender, rw, tempo, m);
    tabela_paginas[ender] = indice;
}

