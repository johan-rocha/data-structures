#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node * left, * right;
} node;

typedef struct stackType
{
    node * data;
    struct stackType * next;
}stackType;

node * insert(node * tree, int value)
{
    if(tree == NULL)
    {
        node * new = malloc(sizeof(node));
        new->key = value;
        new->left = new->right = NULL;
        return new;
    }
    if(value < tree->key)
        tree->left = insert(tree->left, value);
    else
        tree->right = insert(tree->right, value);
    return tree;
}

stackType * top(stackType * stack)
{
    return stack;
}

stackType * push(stackType * stack, node * tree)
{
    stackType * new = malloc(sizeof(stackType));
    new->data = tree;
    new->next = top(stack);//(stack == NULL) ? NULL : stack; // por que nao new->next = stack  ?????
    return new;
}

stackType * pop(stackType * stack, node * tree) //terminar
{
    if(top(stack) != NULL)
    {
        stackType * aux, temp = *(top(stack));
        aux = top(stack);
        stack = stack->next;
        free(aux);
        return temp;
    }
}

int main()
{
    node * tree = NULL;
    tree = insert(tree, 10);
    tree = insert(tree, 8);
    tree = insert(tree, 15);
    tree = insert(tree, 9);

    stackType * stack = NULL;
    stack = push(stack, tree);
    stack = push(stack, tree->left);
}


/*
stackType:
push
top
pop
is_empty

tree:
insert:
caso 1: se a raiz eh nula, insere na raiz.
caso 2: se o valor eh menor que a raiz, insere na subarvore a esquerda, se nao, a direita.

remove
*/