#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *left, *right;
} node;

typedef struct stackNode{
    struct stackNode *next;
    node *root;
}stackNode;

int is_empty(stackNode *stack){
    return stack == NULL;
}

node *top(stackNode *stack){
    return stack->root;
}

void printStack(stackNode * n)
{
    if(n != NULL)
    {
        printf("%d->", n->root->key);
        printStack(n->next);
    }
}

//push
stackNode *push(stackNode *stack, node *r){
    stackNode *new = malloc(sizeof(stackNode));
    new->root = r;
    new->next = stack == NULL ? NULL : stack;
    return new;
}

//pop
node *pop(stackNode ** stack){
    node *poped = top(*stack);
    *stack = (*stack)->next;
    return poped;
}

node *insert(node *root, int value){
    if (root == NULL) {
        node *new = malloc(sizeof(node));
        new->key = value;
        new->left = new->right = NULL;
        return new;
    }
    if (value < root->key)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

void printree(node *root) {
    if (root != NULL){
        printf("%d ", root->key);
        printree(root->left);
        printree(root->right);
    }
}

void emOrdem()
{
    if(roo)
}

int main(){
    node *r = NULL;
    r = insert(r, 10);
    r = insert(r, 5);
    r = insert(r, 2);
    r = insert(r, 15);

    stackNode *stack = NULL;

    stack = push(stack, r);
    stack = push(stack, r->left);
    stack = push(stack, r->right);
    node *t = pop(&stack);
    printf("main: %d\n", stack->root->key);
    printree(r);
    printf("\n\n");
    printStack(stack);
}



