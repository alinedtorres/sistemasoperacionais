

#ifndef __MEMORIA_H__
#define __MEMORIA_H__

typedef struct bloco {
    long int pagina;
    char rw;
    long int tempo_entrada;
    long int tempo_acesso;
} bloco;

typedef struct bloco* memoria;

void memoria_vazia(memoria* m, int tam_memoria);

int indicado_fifo(memoria m, int tam_memoria);

int indicado_lru(memoria m, int tam_memoria);

#endif