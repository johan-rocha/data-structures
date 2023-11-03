#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula * prox;
}celula; 

celula * busca(celula * le, int x)
{
    celula * aux = le->prox;
    while(aux != NULL)
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
    if(le->prox == NULL) //limite /eh possivel o le->prox == NULL e o le->prox->dado == x? NAO
        return NULL; //nesse caso, a impressao da forma que esta nao funciona
    if(le->prox->dado == x)
        return le->prox;
    return busca_rec(le->prox, x);
}