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

int associar_memoria(int indice, long int ender, char rw, long int time_stamp, memoria* m){
	int i = indice + 1;
	memoria m_nova;
	m_nova[i].pagina = ender;	
	m_nova[i].rw = rw;
	m_nova[i].time_stamp = time_stamp;


    *m = m_nova;
	return i;
}
void alterar_memoria(int indice, long int ender, char rw, long int time_stamp, memoria* m){
	memoria m_aux;
	m_aux[indice].rw = rw;
	m_aux[indice].time_stamp = time_stamp;
    *m = m_aux;
}

int verificar_memoria(int* tabela_paginas, long int ender, int indice, char rw, long int time_stamp, memoria* m){
	int novo_indice = 0;
	int i = 0;
	if (tabela_paginas[ender] == 0){
		novo_indice = associar_memoria(indice, ender, rw, time_stamp, &m);
		tabela_paginas[ender] = novo_indice;
	}
	else{
		i = tabela_paginas[ender];
		alterar_memoria(i, ender, rw, time_stamp, &m);
	}

	return novo_indice;
}
