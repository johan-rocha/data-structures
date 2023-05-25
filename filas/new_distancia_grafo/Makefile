MAIN = main_grafo
CFLAGS = -Wall -pedantic -Wextra
CC = gcc

#DIRECTORIES
SRCDIR = src
BINDIR = bin
OBJDIR = obj

#SOURCE
SOURCE = $(wildcard $(SRCDIR)/*.c)
OBJECT = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCE))

all:	objfolder binfolder bin/$(MAIN).out clean

objfolder:
	mkdir -p $(OBJDIR)

binfolder:
	mkdir -p $(BINDIR)

bin/$(MAIN).out:	$(OBJECT)
	$(CC) $(CFLAGS) $< -o $@
	./$@

obj/%.o:	src/%.c src/header.h
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY:	clean objfolder binfolder

clean:
	rm -f $(OBJDIR)/* $(BINDIR)/*
	rmdir $(OBJDIR) $(BINDIR)
