#ifndef __ALGORITMOS__
#define __ALGORITMOS__

#include "memoria.h"

#define KB 1024

int calc_bits_menos_signf(int tam_pagina);

void lru();
void fifo();

void random_alg(int* tabela_paginas, int qtd_pgs, long int ender, char rw, long int time_stamp, memoria* m);
void segunda();

#endif