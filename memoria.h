
typedef struct bloco {
    long int pagina;
    char rw;
    int time_stamp;
} bloco;

typedef struct bloco* memoria;

void memoria_vazia(memoria* m, long int tam_memoria);