#include <stdio.h>
#include <stdlib.h>

typedef struct no 
{
   int chave;
   struct no *esq, *dir;
} no;

no *maximo(no *r) 
{
    // Caso base: se a árvore estiver vazia, retornamos NULL
    if (r == NULL)
        return NULL;

    // Enquanto houver um nó à direita, continuamos descendo na árvore
    while (r->dir != NULL) 
    {
        r = r->dir;
    }

    // Quando não houver mais nós à direita, o nó atual contém o máximo
    return r;
}
