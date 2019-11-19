#ifndef __MEMORIA_H__
#define __MEMORIA_H__

#define TEMPO_RECENTE 20

typedef struct bloco {
    long int pagina;
    char rw;
    long int tempo_entrada;
    long int tempo_acesso;
} bloco;

typedef struct bloco* memoria;

void memoria_vazia(memoria* m, int tam_memoria);

void associar_memoria(int indice, long int ender, char rw, long int tempo, memoria m_nova);

void alterar_memoria(int indice, char rw, long int tempo, memoria m_atualiza);

#endif