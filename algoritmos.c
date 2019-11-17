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

void random_alg(int* tabela_paginas, int qtd_pgs, long int ender, char rw, long int time_stamp, memoria* m){
			int indice = rand() % qtd_pgs;
			int novo_indice = associar_memoria(indice, ender, rw, time_stamp, m);
			tabela_paginas[ender] = novo_indice;
}