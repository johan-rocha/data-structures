#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H
#include <stdio.h>
#include <stdlib.h>

/*STRUCTURES*/
typedef struct celula
{
    int dado;
    struct celula * prox;
}celula;


/*FUNCTIONS PROTOTYPES - MAIN*/
celula * criar_lista();

void inserir_na_lista(celula * head, int elemento);
int remover_da_lista(celula * head, int elemento);
int imprimir_lista(celula * head);

/*FUNCTIONS PROTOTYPES - busca*/
celula * busca_rec(celula * le, int x);
celula * busca(celula * le, int x);





#endif