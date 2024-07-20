#include <stdio.h>
#include <stdlib.h>
/* Functions:
push()
pop()
peek()
size()
isEmpty()

 */

typedef struct no
{
   int dado;
   struct no *esq, *dir;
} no;

typedef struct StackNode
{
    no * data;
    struct StackNode * next;
} StackNode;


StackNode * push(no * data, StackNode * top)
{
    if(top == NULL)
    {
        top = malloc(sizeof(StackNode));
        top->data = data;
        top->next = NULL;
    }
    else
    {
        StackNode * aux = malloc(sizeof(StackNode));
        aux->data = top->data;
        aux->next = top->next;
        top->data = data;
        top->next = aux;
    }
    return top;
}

no * pop(StackNode **top)
{
    if (*top == NULL) {
        printf("Pilha vazia.\n");
        return NULL;
    }
    StackNode *temp = *top;
    no * poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

int isEmpty(StackNode *top)
{
    return top == NULL;
}

no * peek(StackNode *top)
{
    if (top == NULL) {
        printf("Pilha vazia.\n");
        return NULL;
    }
    return top->data;
}

int size(StackNode *top)
{
    int count = 0;
    StackNode *current = top;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void pre_ordem(no *raiz)
{
    StackNode *stack_top = NULL;

    if (raiz != NULL) 
    {
        stack_top = push(raiz, stack_top);
        while (!isEmpty(stack_top)) 
        {
            no *current = pop(&stack_top);
            printf("%d ", current->dado);

            if (current->dir != NULL)
                stack_top = push(current->dir, stack_top);
            if (current->esq != NULL)
                stack_top = push(current->esq, stack_top);
        }
    }
    // Liberando a memória restante
    while (!isEmpty(stack_top)) 
    {
        no *poppedNode = pop(&stack_top);
        free(poppedNode);
    }
}

/* int main()
{

} */