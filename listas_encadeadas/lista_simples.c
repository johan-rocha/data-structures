#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula * prox;
}celula;

celula * criar_lista();
void excluir_lista(); // a fazer

void insere_lista();

int main()
{
    celula * head_lista_feita = criar_lista();

}

celula * criar_lista()
{
    celula * head = malloc(sizeof(head));
    if(!head);
        abort();
    head->prox = NULL;
    return head;
}

void insere_lista()
{
    
}