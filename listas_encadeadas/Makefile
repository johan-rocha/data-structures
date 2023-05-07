#FLAGS
CFLAGS = -Wall -Wextra -pedantic

#programa
program=lista_simples

all:	run

run:	clean compile
	./$(program).out

debug:	clean $(program).o busca.o
	gcc $(CFLAGS) $(program).o busca.o -g
	gdb ./a.out


compile: $(program).o busca.o
	gcc $(CFLAGS) $(program).o busca.o -o $(program).out

busca.o:	header.h
	gcc $(CFLAGS) -c busca.c -o busca.o

$(program).o:	header.h
	gcc $(CFLAGS) -c $(program).c -o $(program).o 

clean:
	rm *.out
	rm *.o
	clear
