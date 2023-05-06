NAME=transporte

all:	clear

clear:	run
	rm *.out

run:	compile
	./$(NAME).out  < entradas.txt

compile:
	gcc $(NAME).c -Wall -pedantic -o $(NAME).out
