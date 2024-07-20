#include <stdio.h>
#include <stdlib.h>

typedef struct no 
{
   int chave;
   struct no *esq, *dir;
} no;

// Função para inserir um novo valor x na árvore binária de busca
no *inserir(no *r, int x) 
{
    // Caso base: se a árvore estiver vazia, criamos um novo nó
    if (r == NULL) {
        no *novo = (no *) malloc(sizeof(no));
        if (novo == NULL) {
            fprintf(stderr, "Erro ao alocar memória!\n");
            exit(EXIT_FAILURE);
        }
        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    // Caso contrário, navegamos na árvore para encontrar a posição correta
    if (x < r->chave) 
    {
        // Inserir na subárvore esquerda
        r->esq = inserir(r->esq, x);
    } else if (x > r->chave) {
        // Inserir na subárvore direita
        r->dir = inserir(r->dir, x);
    }
    // Se x já existe na árvore, não fazemos nada (não inserimos repetições)

    // Retorna o ponteiro para a raiz da árvore após a inserção
    return r;
}
