
#ifndef __TABELA_PAG__
#define __TABELA_PAG__


//int* tabela_paginas;

void tabela_vazia(int** tabela_paginas, long int tam_vetor);

void associar_memoria(int indice, long int ender, char rw, long int tempo, memoria m_nova);

void alterar_memoria(int indice, char rw, long int tempo, memoria m_atualiza);

int verificar_memoria(int* tabela_paginas, long int ender, int indice, char rw, long int tempo, memoria m, int tam_memoria);

#endif