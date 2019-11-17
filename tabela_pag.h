
#ifndef __TABELA_PAG__
#define __TABELA_PAG__


//int* tabela_paginas;

void tabela_vazia(int* tabela_paginas, long int tam_vetor);

int associar_memoria(int indice, long int ender, char rw, long int time_stamp, memoria* m);

void alterar_memoria(int indice, long int ender, char rw, long int time_stamp, memoria* m);

int verificar_memoria(int* tabela_paginas, long int ender, int indice, char rw, long int time_stamp, memoria* m, int qtd_pgs);

#endif