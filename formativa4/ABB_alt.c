#include <stdio.h>
#include <stdlib.h>

typedef struct no 
{
   int chave;
   struct no *esq, *dir;
} no;

// Função auxiliar para calcular o máximo entre dois inteiros
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

// Função para calcular a altura da árvore binária de busca
int altura(no *r) 
{
    // Caso base: se o nó for NULL, a altura é 0
    if (r == NULL)
        return 0;

    // Recursivamente calcula a altura dos subárvores esquerda e direita
    int altura_esq = altura(r->esq);
    int altura_dir = altura(r->dir);

    // A altura da árvore é o máximo entre as alturas das subárvores mais 1
    return 1 + max(altura_esq, altura_dir);
}
