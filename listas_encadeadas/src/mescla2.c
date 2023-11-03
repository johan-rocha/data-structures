#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula * prox;
}celula;

void mescla_listas(celula * l1, celula *l2, celula * l3)
{
    celula * auxl1 = l1->prox;
    celula * auxl2 = l2->prox;
    celula * auxl3 = l3; //tem que começar pela cabeça, onde se encontra o ponteiro, caso seja NULL

    while(auxl1 != NULL && auxl2 != NULL)
    {
        if(auxl1->dado <= auxl2->dado)
        {
            auxl3->prox = auxl1;
            auxl1 = auxl1->prox; //caso auxl1 seja != de NULL
        }
        else
        {
            auxl3->prox = auxl2;
            auxl2 = auxl2->prox; //caso auxl2 seja != de NULL
        }
        auxl3 = auxl3->prox;
    }
    if(auxl1 == NULL)
    {
        auxl3->prox = auxl2;
    }
    else if(auxl2 == NULL)
    {
        auxl3->prox = auxl1;
    }
    l1->prox = NULL;
    l2->prox = NULL;

    //se l1 ou l2 chegar em NULL, o resto da lista do outro vai ser o final de l3
}