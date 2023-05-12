MAIN = lista_simples
CFLAGS = -Wall -pedantic -Wextra
CC = gcc
#LDFLAG = -lm

#DIRECTIORIES
SRCDIR = src
OBJDIR = obj
BINDIR = bin

#SOURCE ARCHIVES
SOURCE = $(wildcard $(SRCDIR)/*.c)

#OBJECT ARCHIVES
OBJECT = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCE))


all:	binfolder objfolder $(BINDIR)/$(MAIN).out clean

binfolder:
	@ echo "Gerando pasta bin"
	mkdir -p $(BINDIR)
objfolder:
	@ echo "Gerando pasta obj"
	mkdir -p $(OBJDIR)

bin/$(MAIN).out:	$(OBJECT)
	@ echo "linkando no .out"
	$(CC) $(CFLAGS) $(OBJECT) -o $@
	./$(BINDIR)/$(MAIN).out < ./src/input.txt 

obj/%.o:	src/%.c src/header.h
	@ echo "Compilando objetos"
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	clean objfolder binfolder

clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*
	rmdir $(BINDIR) $(OBJDIR)
