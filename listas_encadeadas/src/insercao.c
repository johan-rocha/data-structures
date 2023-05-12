#include "header.h"

void insere_inicio(celula * le, int x)
{
    celula * novo = malloc(sizeof(celula));

    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

/* celula * anterior(celula * le, int y) //modularizada
{
    celula * aux = le;
    
    while(aux->prox != NULL)
    {
        if(aux->prox->dado == y)
            return aux;
        aux = aux->prox;
    }
    return NULL;
} */

void insere_antes(celula * le, int x, int y)
{
    //insere o elemento depois do anterior
    celula * novo = malloc(sizeof(celula));
    celula * ant = le;      //anterior(le, y);

    while(ant->prox != NULL)
    {
        if(ant->prox->dado == y)
            break;
        ant = ant->prox;
    }
    
    novo->dado = x;
    novo->prox = ant->prox;
    ant->prox = novo;

}