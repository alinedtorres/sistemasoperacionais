

#ifndef __MEMORIA_H__
#define __MEMORIA_H__

typedef struct bloco {
    long int pagina;
    char rw;
    long int time_stamp;
} bloco;

typedef struct bloco* memoria;

void memoria_vazia(memoria* m, int tam_memoria);

int bloco_mais_antigo(memoria m, int tam_memoria);

#endif