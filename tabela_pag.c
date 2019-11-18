
#include "memoria.h"
#include "tabela_pag.h"
#include <stdio.h>
#include <stdlib.h>

void tabela_vazia(int** tabela_paginas, long int tam_vetor){
    int* tabela_nova = (int*) malloc(sizeof(int)*tam_vetor);
    printf("\n tamanho vetor %ld", tam_vetor);
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

void associar_memoria(int indice, long int ender, char rw, long int time_stamp, memoria* m){
	memoria m_nova;
	m_nova[indice].pagina = ender;	
	m_nova[indice].rw = rw;
	m_nova[indice].time_stamp = time_stamp;


    *m = m_nova;
}
void alterar_memoria(int indice, long int ender, char rw, long int time_stamp, memoria* m){
	memoria m_aux;
	m_aux[indice].rw = rw;
	m_aux[indice].time_stamp = time_stamp;
    *m = m_aux;
}

int verificar_memoria(int* tabela_paginas, long int ender, int indice, char rw, long int time_stamp, memoria* m, int qtd_pgs){
		int i = 0;

	if (tabela_paginas[ender] == -1){
			if (indice < qtd_pgs){
			
			associar_memoria(indice, ender, rw, time_stamp, &m);
			//tabela_paginas[ender] = indice;
			return 0;
		}
		else{
			//pagefault
		    return -2;
		}
	}
	else{
		//i = tabela_paginas[ender];
		//alterar_memoria(i, ender, rw, time_stamp, &m);	
		return -1;
	}

}
