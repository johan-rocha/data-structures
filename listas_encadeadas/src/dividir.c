#include "header.h"

void divide_lista (celula *l, celula *l1, celula *l2)
{
    celula * auxl = l;
    celula * auxSubs;

    while(auxl->prox != NULL)
    {
        auxSubs = NULL;
        if(auxl->prox->dado%2 == 0)
        {
            //apontar l2 para elemento e desapontar l para elemento

            //elemento de l2 que aponta para NULL passa a apontar para elemento encontrado em l
            auxSubs = ultimo_elemento(l2);
            auxSubs->prox = auxl->prox;
            //elemento anterior ao encontrado em l passa a apontar para quem o encontrado aponta
            auxl->prox = auxl->prox->prox;
            //O encontrado passa a apontar para NULL
            auxSubs->prox->prox = NULL;
        }
        else
        {
            //apontar l1 para elemento e desapontar l para elemento
            auxSubs = ultimo_elemento(l2);
            auxSubs->prox = auxl->prox;
            auxl = auxl->prox->prox;
            auxSubs->prox->prox = NULL;
        }
        auxl = auxl->prox;
    }
}

celula * ultimo_elemento(celula * x)
{
    celula * temp = x;

    while (temp->prox != NULL)
        temp = temp->prox;
    return temp;
}