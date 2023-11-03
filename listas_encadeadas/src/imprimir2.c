#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula * prox;
}celula; 

void imprime(celula * le);
void imprime_rec(celula * le);

void imprime(celula * le)
{
    le = le->prox;
    for(; le != NULL; le = le->prox)
        printf("%d -> ", le->dado);
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



