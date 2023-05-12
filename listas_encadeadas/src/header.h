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

/*FUNCTIONS PROTOTYPES - gerencia (nao oficial)*/
void inserir_na_lista(celula * head, int elemento);
int remover_da_lista(celula * head, int elemento);
int imprimir_lista(celula * head);

/*FUNCTIONS PROTOTYPES - busca*/
celula * busca_rec(celula * le, int x);
celula * busca(celula * le, int x);

/*FUNCTIONS PROTOTYPES - divide*/
void divide_lista (celula *l, celula *l1, celula *l2);

/*FUNCTIONS PROTOTYPES - imprime*/
void imprime(celula * le);
void imprime_rec(celula * le);

/*FUNCTIONS PROTOTYPES - insercao*/
void insere_inicio(celula * le, int x);
void insere_antes(celula * le, int x, int y);

/*FUNCTIONS PROTOTYPES - mescla*/
void mescla_listas(celula * l1, celula *l2, celula * l3);

/*FUNCTIONS PROTOTYPES - remove*/
int remove_depois(celula * p); //remove depois do ponteiro p
void remove_elemento(celula * le, int x); //remove a primeira ocorrência de x
void remove_todos_elementos(celula * le, int x); //remove todas as ocorrencias de x na lista le;

#endif