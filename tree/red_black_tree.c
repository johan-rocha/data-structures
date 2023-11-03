/* 

https://www.geeksforgeeks.org/introduction-to-red-black-tree/
https://ocw.mit.edu/courses/6-046j-introduction-to-algorithms-sma-5503-fall-2005/resources/lecture-10-red-black-trees-rotations-insertions-deletions/

Árvores Rubro-negras esquerdistas

São árvores binárias de busca que seguem as seguintes regras:

1) Todo nó da árvore é vermelho ou preto.

2) A raiz é preta.

3) Se um nó é vermelho, então:
    - seus dois filhos são pretos
    - é filho esquerdo de um nó preto

4) Em cada nó, o caminho para qualquer uma de suas folhas possui a mesma quantidade nós pretos. *******
    - O próprio nó não conta
    - altura negra ******

5) As folhas são NULL e têm cor preta.



INSERÇÃO:
- todo nó que a gente insere é vermelho

OPERAÇÕES DE CORREÇÃO
1) Rotações (o que sobe troca de cor com o que desce)
    - rotação à direita
    - rotação à esquerda

3) Elevação da cor (os dois filhos tem que ser vermelhos)


*/

#include <stdio.h>
#include <stdlib.h>

typedef int data;

typedef enum colors{red, black}colors;

typedef struct node
{
    data info;
    struct node * left, * right;
    colors color;
}node;

node * rotacao_esquerda(node * raiz) //complexidade O(1)
{
    node * x = raiz->right;
    raiz->right = x->left;
    x->left = raiz;
    x->color = raiz->color;
    raiz->color = red;
    return x; //retorna o x como raiz
}

node * rotacao_direita(node * raiz)
{
    node * a = raiz->left;
    raiz->left = a->right;
    a->right = raiz;
    a->color = raiz->color;
    raiz->color = red;
    return a;
}

node * fix_up_color(node * raiz) //sobe cor
{
    raiz->color = red;
    raiz->left->color = black;
    raiz->right->color = black;
}

node * insert(node * raiz, int ch)
{
    raiz = insert_rec(raiz, ch);
    raiz->color = black;
    return raiz;
}

node * insert_rec(node * raiz, int ch)
{
    if(raiz == NULL) //chegou na folha
    {
        node * new = malloc(sizeof(node));
        new->left = new->right = NULL;
        new->info = ch;
        new->color = red; //todo inserido é vermelho
        return new;
    }
    if(ch < raiz->info) raiz->left = insert_rec(raiz->left, ch);
    else raiz->right = insert_rec(raiz->right, ch);
    return fix(raiz); //conserta a arvore
}

/*
1º caso bom de inserção:
    insere como filho esquerdo de um nó preto

2.1º caso ruim de inserção:
    insere como filho direito de um nó preto
    correção: rotação à esquerda

2.2º caso ruim de inserção:
    ao lado de filho esquerdo vermelho (os dois ficarão vermelhos)
    correção: sobe cor
    obs: pode causar problema se r for filho direito ou se for filho de um nó vermelho

3º caso ruim de inserção:
    insere como filho esquerdo de um nó vermelho
    correção: rotaciona o pai(vai deixar para resolver depois)

4º caso ruim de inserção
    insere como filho direito de um nó vermelho

--------------------------------------PROBLEMAS-----------------------------------

1º - raiz com filho esquerdo preto e filho direito vermelho
solução: rotação à esquerda (casos 2.1 e 4)

2º - raiz preta e dois filhos vermelhos
solução: subir cor(caso 2.2)

3º - raiz preta com filho esquerdo e neto mais à esquerda vermelho.
solução: rotação à direita. (casos 2.2, 3 e 4)


*/

node * fix(node * raiz)
{
    if(raiz->left->color == black && raiz->right->color == red)
        return rotacao_esquerda(raiz);
    if(raiz->left->color == red && raiz->right->color == red)
    {
        fix_up_color(raiz);
        return raiz;
    }
    if(raiz->left->color == red && raiz->left->left == red)
    {
        raiz = rotacao_direita(raiz);
        fix_up_color(raiz);
        return raiz;
    }

    //obs: verificar apropriadamente se nenhuma componente é nula e considerar que NULL é preto(corrigir depois, Johan)
}