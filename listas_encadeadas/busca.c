#include "header.h"

celula * busca(celula * le, int x)
{
    celula * aux = le->prox;
    while(aux != NULL) //um int não pode ser NULL! alterar.
    {
        if(aux->dado == x)
            return aux;
        else aux = aux->prox;
    }
    //retornaria que nao existe o elemento
    return NULL;
}

celula * busca_rec(celula * le, int x)
{
    if(le == NULL)
        return le;
    if(le->dado == x)
        return le;
    if(le->prox->dado != x)
        return busca_rec(le->prox, x);
    return NULL;
}