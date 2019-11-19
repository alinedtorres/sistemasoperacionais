
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

int verificar_memoria(int* tabela_paginas, long int ender, int indice, char rw, long int tempo, memoria m, int tam_memoria){
	int i = 0;

	if (tabela_paginas[ender] == -1){
		if (indice < tam_memoria){
			associar_memoria(indice, ender, rw, tempo, m);
			tabela_paginas[ender] = indice;
			return 0;
		}
		else{
		    return -2;
		}
	}
	else{
		i = tabela_paginas[ender];
		alterar_memoria(i, rw, tempo, m);
		return -1;
	}

}
