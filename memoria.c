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

void associar_memoria(int indice, long int ender, char rw, long int tempo, memoria m_nova){
	m_nova[indice].pagina = ender;	
	m_nova[indice].rw = rw;
	m_nova[indice].tempo_entrada = tempo;
	m_nova[indice].tempo_acesso = tempo;
}

void alterar_memoria(int indice, char rw, long int tempo, memoria m_atualiza){
	m_atualiza[indice].rw = rw;
	m_atualiza[indice].tempo_acesso = tempo;
}


