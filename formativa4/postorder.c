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

void pos_ordem(no *raiz) {
    if (raiz == NULL) return;

    StackNode *stack_top = NULL;
    StackNode *visited = NULL;
    no *current = raiz;

    while (!isEmpty(stack_top) || current != NULL) {
        if (current != NULL) {
            stack_top = push(current, stack_top);
            current = current->esq;
        } else {
            no *peekNode = peek(stack_top);
            if (peekNode->dir != NULL && (visited == NULL || peekNode->dir != peek(visited))) {
                current = peekNode->dir;
            } else {
                printf("%d ", peekNode->dado);
                visited = push(pop(&stack_top), visited);
            }
        }
    }

    // Limpar pilha de visitados
    while (!isEmpty(visited)) {
        pop(&visited);
    }
}

/* int main()
{

} */