#include "header.h"

void imprime(celula * le)
{
    celula * aux = le->prox;
    while(aux != NULL)
    {
        printf("%d -> ", aux->dado);
        aux = aux->prox;
    }
    puts("NULL");
}

void imprime_rec(celula * le)
{
    if(le->prox != NULL)
    {
        printf("%d -> ", le->prox->dado);
        imprime_rec(le->prox);
    }
    else
        puts("NULL");
}