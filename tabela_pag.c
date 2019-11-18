
#include "memoria.h"
#include "tabela_pag.h"
#include <stdio.h>
#include <stdlib.h>

void tabela_vazia(int** tabela_paginas, long int tam_vetor){
    int* tabela_nova = (int*) malloc(sizeof(int)*tam_vetor);
    int i;
    if(tabela_nova == NULL){
        printf("\nErro na alocacao para o novo vetor 'tabela nova'!\n");
        exit(-1);
    } else {

        for(i = 0; i < tam_vetor; i++){
            tabela_nova[i] = -1;
        }

        *tabela_paginas = tabela_nova;
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

int verificar_memoria(int* tabela_paginas, long int ender, int indice, char rw, long int tempo, memoria m, int tam_memoria){
	int i = 0;

	if (tabela_paginas[ender] == -1){
		if (indice < tam_memoria){
			associar_memoria(indice, ender, rw, tempo, m);
			tabela_paginas[ender] = indice;
			//printf("\nSalvo: %X na memoria: %d", ender, indice);
			return 0;
		}
		else{
			//printf("\nPage Fault");
		    return -2;
		}
	}
	else{
		i = tabela_paginas[ender];
		alterar_memoria(i, rw, tempo, m);
		//printf("\nAtualizado: %X na memoria: %d", ender, i);	
		return -1;
	}

}
