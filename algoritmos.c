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

void fifo_lru_alg(int* tabela_paginas, int qtd_pgs, long int ender, char rw, long int time_stamp, memoria m, char fifo_ou_lru){
    int mais_antigo, novo_indice;
    long int ultimo;
    if(fifo_ou_lru){ //0 para fifo 1 para lru
        mais_antigo = indicado_lru(m, qtd_pgs);
    } else {
        mais_antigo = indicado_fifo(m, qtd_pgs);
    }
    ultimo = m[mais_antigo].pagina;
    novo_indice = associar_memoria(tabela_paginas[ultimo], ender, rw, time_stamp, &m);
    tabela_paginas[ender] = tabela_paginas[ultimo];
    tabela_paginas[ultimo] = -1;
}
