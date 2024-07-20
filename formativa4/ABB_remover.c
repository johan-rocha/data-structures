#include <stdio.h>
#include <stdlib.h>

typedef struct no 
{
   int chave;
   struct no *esq, *dir;
} no;

// Função auxiliar para encontrar o antecessor na árvore
no *encontrar_antecessor(no *r) 
{
    if (r == NULL)
        return NULL;

    // Vai para o nó mais à direita na subárvore esquerda
    while (r->dir != NULL) 
    {
        r = r->dir;
    }
    return r;
}

// Função para remover um valor x na árvore binária de busca
no *remover(no *r, int x) 
{
    // Caso base: se a árvore estiver vazia, retorna NULL
    if (r == NULL)
        return NULL;

    // Se x é menor que a chave atual, vai para a subárvore esquerda
    if (x < r->chave) 
    {
        r->esq = remover(r->esq, x);
    }
    // Se x é maior que a chave atual, vai para a subárvore direita
    else if (x > r->chave) 
    {
        r->dir = remover(r->dir, x);
    }
    // Se encontrou o nó a ser removido
    else 
    {
        // Caso 1: nó sem filho ou com apenas um filho
        if (r->esq == NULL) 
        {
            no *temp = r->dir;
            free(r);
            return temp;
        } 
        else if (r->dir == NULL) 
        {
            no *temp = r->esq;
            free(r);
            return temp;
        }

        // Caso 2: nó com dois filhos
        // Encontrar o antecessor na subárvore esquerda
        no *antecessor = encontrar_antecessor(r->esq);
        // Copiar o valor do antecessor para o nó atual
        r->chave = antecessor->chave;
        // Remover o antecessor recursivamente
        r->esq = remover(r->esq, antecessor->chave);
    }

    // Retorna o ponteiro para a raiz da árvore após a remoção
    return r;
}
