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
        padrao.time_stamp = -1;

        //Copia o bloco padrão para cada bloco alocado para a memória
        for(i = 0; i < tam_memoria; i++){
            nova[i] = padrao;
        }

        //Repassa o endereço da nova memória alocada e inicializada
        *m = nova;
    }
}

int bloco_mais_antigo(memoria m, int tam_memoria){
    int i, end_bloco = 0;
    long int time;
    time = m[0].time_stamp;
    //Passa por todo o vetor até encontrar o menor tempo
    for(i = 1; i < tam_memoria; i++){
        if(time > m[i].time_stamp){
            time = m[i].time_stamp;
            end_bloco = i;
        }
    }
    return end_bloco;
}

