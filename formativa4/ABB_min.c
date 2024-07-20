#include <stdio.h>
#include <stdlib.h>

typedef struct no 
{
   int chave;
   struct no *esq, *dir;
} no;

no *minimo(no *r) 
{
    // Caso base: se a árvore estiver vazia, retornamos NULL
    if (r == NULL)
        return NULL;

    // Enquanto houver um nó à esquerda, continuamos descendo na árvore
    while (r->esq != NULL) 
    {
        r = r->esq;
    }

    // Quando não houver mais nós à esquerda, o nó atual contém o mínimo
    return r;
}