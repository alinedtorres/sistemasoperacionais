#ifndef __ALGORITMOS__
#define __ALGORITMOS__

#include "memoria.h"

#define KB 1024

int calc_bits_menos_signf(int tam_pagina);

//void random_alg(int* tabela_paginas, long int ender, char rw, long int tempo, memoria m, int tam_memoria);

//fifo_ou_lru deve ser 0 para fifo 1 para lru 2 para random 3 para 2a
void algoritmos_reposicao(int* tabela_paginas, long int ender, char rw, long int tempo, memoria m, int tam_memoria, int escolhido);


#endif