#include "header.h"

int remove_depois(celula * p) //remove depois do ponteiro p
{
    if(p->prox != NULL)
    {
        celula * lixo = p->prox;
        p->prox = lixo->prox;
        free(lixo);
        return 0; //se der certo
    }
    return 1; //se der errado
}

void remove_elemento(celula * le, int x) //remove a primeira ocorrência de x
{
    celula * aux = le;

    while(aux->prox != NULL)
    {
        if(aux->prox->dado == x)
        {
            remove_depois(aux);
            break;   
        }
        aux = aux->prox; //nao precisa de else porque a iteração so acontece ate achar o elemento
    }
}

void remove_todos_elementos(celula * le, int x) //remove todas as ocorrencias de x na lista le;
{
    celula * aux = le;

    while(aux->prox != NULL)
    {
        if(aux->prox->dado == x)
            remove_depois(aux);
        else
            aux = aux->prox;
    }
}