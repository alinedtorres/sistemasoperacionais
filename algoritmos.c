
#define KB 1024

int calc_bits_menos_signf(int tam_pagina){
    int tamanho = tam_pagina, bits = 0;
    tamanho *= KB;
    while(tamanho > 1){
        tamanho = tamanho >> 1;
        bits++;
    }
    return bits;
}
