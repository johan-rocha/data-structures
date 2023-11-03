//qtde nos: 2h+1−1

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int dado;
    struct node * left, * right;
    struct node * dad;
}node;

node * cria_arvore(int dado, node * left, node * right)
{
    node * root = malloc(sizeof(node));
    root->left = left;
    root->right = right;
    root->dado = dado;
    return root;
}

node * busca(node * root, int x)
{
    node * left;

    if(root == NULL || root->dado == x) //caso base
        return root;

    left = busca(root->left, x);
    
    if(left != NULL) return left;
    return busca(root->right, x);
}

int main()
{
    node * p1 = cria_arvore(10, NULL, NULL);
    p1 = cria_arvore(8, p1, NULL);

    node * p2 = cria_arvore(6, NULL, NULL);
    p1 = cria_arvore(4, p2, p1); //subarvore a esquerda

    p2 = cria_arvore(2, NULL, NULL);
    node * p3 = cria_arvore(1, NULL, NULL);
    p2 = cria_arvore(7, p2, p3);

    p1 = cria_arvore(3, p1, p2);
}