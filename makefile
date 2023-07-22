mmn.o: main.o pre_asembler.o
	gcc -Wall -ansi -pedantic -g main.o pre_asembler.o -o mmn
main.o: main.c data.h
	gcc -c -ansi -Wall -pedantic main.c -o main.o
pre_asembler.o: pre_asembler.c data.h
	gcc -c -ansi -Wall -pedantic pre_asembler.c -o pre_asembler.o
