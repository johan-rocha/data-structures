MAIN = main_grafo
CFLAGS = -Wall -pedantic -Wextra
CC = gcc
#LDFLAG = -lm

#DIRECTORIES
BINDIR = bin
SRCDIR = src
OBJDIR = obj

#SOURCE ARCHIVES  - gera uma string com o nome de todos os arquivos na pasta src e atribui a SOURCE
SOURCE = $(wildcard $(SRCDIR)/*.c)

#OBJECTS ARCHIVES - altera todas as ocorrencias da substring .c para .o, atribuindo a OBJECT
OBJECT = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCE))

all:	objfolder binfolder bin/$(MAIN).out clean

objfolder:
	mkdir -p $(OBJDIR)

binfolder:
	mkdir -p $(BINDIR)

bin/$(MAIN).out:	$(OBJECT)
	@ echo "Linkando objetos"
	$(CC) $(CFLAGS) $(OBJECT) -o $@
	./$@


obj/%.o:	src/%.c src/header.h
	@ echo "Compilando objetos"
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	clean objfolder binfolder

clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*
	rmdir $(BINDIR) $(OBJDIR)




