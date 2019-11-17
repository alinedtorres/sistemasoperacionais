int* tabela_paginas;

void tabela_vazia(int* tabela_paginas, long int tam_vetor){
    int* tabela_nova = (int*) malloc(sizeof(int)*tam_vetor);
    int i;
    if(tabela_nova == NULL){
        printf("\nErro na alocacao para o novo vetor 'tabela nova'!\n");
        exit(-1);
    } else {

        for(i = 0; i < tam_vetor; i++){
            tabela_nova[i] = 0;
        }

        *tabela_paginas = tabela_nova;
    }
}

int verificar_memoria(int* tabela_paginas, long int ender, int indice, char rw, long int time_stamp, memoria* m){
	int novo_indice = 0;
	if (tabela_paginas[ender] == 0){
		novo_indice = associar_memoria(indice, ender, rw, time_stamp, m);
		tabela_paginas[ender] = novo_indice;
	}
	else{
		i = tabela_paginas[ender];
		alterar_memoria(i, ender, rw, time_stamp, m);
	}

	return novo_indice;
}

int associar_memoria(int indice, long int ender, char rw, long int time_stamp, memoria* m){
	int i = indice + 1;
	m[i].pagina = ender;	
	m[i].rw = rw;
	m[i].time_stamp = time_stamp;
	return i;
}
void alterar_memoria(int indice, long int ender, char rw, long int time_stamp, memoria* m){
	m[indice].rw = rw;
	m[indice].time_stamp = time_stamp;
}