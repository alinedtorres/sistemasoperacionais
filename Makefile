main:	main.o	algoritmos.o	tabela_pag.o memoria.o
	gcc main.o algoritmos.o tabela_pag.o memoria.o -o main -lm

main.o:	main.c
	gcc -c main.c

algoritmos.o:	algoritmos.c	algoritmos.h
	gcc -c algoritmos.c

tabela_pag.o:	tabela_pag.c	tabela_pag.h
	gcc -c tabela_pag.c

memoria.o:	memoria.c	memoria.h
	gcc -c memoria.c
