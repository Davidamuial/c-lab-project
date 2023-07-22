mmn.o: main.o function.o
	gcc -Wall -ansi -pedantic -g main.o function.o -o mmn
main.o: main.c data.h
	gcc -c -ansi -Wall -pedantic main.c -o main.o
function.o: function.c data.h
	gcc -c -ansi -Wall -pedantic function.c -o function.o
