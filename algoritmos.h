#ifndef __ALGORITMOS__
#define __ALGORITMOS__

#include "memoria.h"

#define KB 1024

int calc_bits_menos_signf(int tam_pagina);

//fifo_ou_lru deve ser 0 para fifo 1 para lru 2 para random 3 para 2a
int algoritmos_reposicao(int* tabela_paginas, long int ender, char rw, long int tempo, memoria m, int tam_memoria, int escolhido);

int indicado_fifo(memoria m, int tam_memoria, long int tempo_atual);

int indicado_lru(memoria m, int tam_memoria, long int tempo_atual);

int indicado_segunda(memoria m, int tam_memoria, long int tempo_atual);


#endif