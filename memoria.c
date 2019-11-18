#include <stdlib.h>
#include <stdio.h>

#include "memoria.h"

void memoria_vazia(memoria* m, int tam_memoria){
    memoria nova = (bloco*) malloc(sizeof(bloco)*tam_memoria);
    bloco padrao;
    int i;
    if(nova == NULL){
        printf("\nErro na alocacao para o novo vetor 'memoria'!\n");
        exit(-1);
    } else {
        //Seta dados iniciais padrão de blocos vazios na memória
        padrao.pagina = -1;
        padrao.rw = '\0';
        padrao.tempo_entrada = -1;
        padrao.tempo_acesso = -1;

        //Copia o bloco padrão para cada bloco alocado para a memória
        for(i = 0; i < tam_memoria; i++){
            nova[i] = padrao;
        }

        //Repassa o endereço da nova memória alocada e inicializada
        *m = nova;
    }
}

int indicado_fifo(memoria m, int tam_memoria, long int tempo_atual){
    int i, ender_bloco = 0;
    long int tempo = tempo_atual;
    //Passa por todo o vetor até encontrar o menor tempo
    for(i = 0; i < tam_memoria; i++){
        if(tempo > m[i].tempo_entrada){
            tempo = m[i].tempo_entrada;
            ender_bloco = i;
        }
    }
    return ender_bloco;
}

int indicado_lru(memoria m, int tam_memoria, long int tempo_atual){
    int i, ender_bloco = 0;
    long int tempo = tempo_atual;
    //Passa por todo o vetor até encontrar o menor tempo
    for(i = 0; i < tam_memoria; i++){
        if(tempo > m[i].tempo_acesso){
            tempo = m[i].tempo_acesso;
            ender_bloco = i;
        }
    }
    return ender_bloco;
}

int indicado_segunda(memoria m, int tam_memoria, long int tempo_atual){
    int i, ender_bloco = 0;
    long int tempo = tempo_atual;
    for(i = 0; i < tam_memoria; i++){
        if((tempo_atual - m[i].tempo_acesso) > TEMPO_RECENTE){
            if(tempo > m[i].tempo_entrada){
                tempo = m[i].tempo_entrada;
                ender_bloco = i;
            }
        }
    }
    return ender_bloco;
}

