#include "header.h"

void divide_lista (celula *l, celula *l1, celula *l2)
{
    celula * aux = l->prox;

    while(aux != NULL)
    {
        if(aux->dado%2 == 0)
            //inserir em l2
            inserir_na_lista(l2, aux->dado);
        else
            //inserir em l1
            inserir_na_lista(l1, aux->dado);
        aux = aux->prox;
    }
}