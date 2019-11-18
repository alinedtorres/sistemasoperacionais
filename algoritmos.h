#ifndef __ALGORITMOS__
#define __ALGORITMOS__

#include "memoria.h"

#define KB 1024

int calc_bits_menos_signf(int tam_pagina);

void random_alg(int* tabela_paginas, int qtd_pgs, long int ender, char rw, long int time_stamp, memoria* m);

//fifo_ou_lru deve ser 0 para fifo ou 1 para lru
void fifo_lru_alg(int* tabela_paginas, int qtd_pgs, long int ender, char rw, long int time_stamp, memoria m, char fifo_ou_lru);


#endif