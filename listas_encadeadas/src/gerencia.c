#include "header.h"

/*FUNCTIONS DEFINITIONS*/
celula * criar_lista()
{
    celula * head = malloc(sizeof(celula));
    if(!head)
        abort();
    head->prox = NULL;
    return head;
}
void inserir_na_lista(celula * head, int elemento) //insere no final da lista
{
    celula * novo = malloc(sizeof(celula));
    celula * aux;
    if(!novo)
        abort();
    aux = head;
    novo->dado = elemento;

    while(aux->prox != NULL) aux = aux->prox;
    aux->prox = novo;
    novo->prox = NULL;
}
int remover_da_lista(celula * head, int elemento) //provavelmente vai usar busca, ficar atento
{
    celula * lixo = head->prox;
    celula * aux = head;
    //caso 1: nao haver elementos a serem removidos
    if(head->prox == NULL)
        return 1;

    while(lixo->dado != elemento && lixo->prox != NULL) 
    {
        lixo = lixo->prox;
        aux = aux->prox;
    }

    //caso 4: nao haver o elemento
    if(lixo->prox == NULL && lixo->dado != elemento)
        return 1;
    //caso 2: remover no inicio ou meio da lista
    //caso 3: remover no final da lista
    aux->prox = lixo->prox;
    lixo->prox = NULL;
    free(lixo);
    return 0; 
}
int imprimir_lista(celula * head)
{
    celula * aux = head;

    if(aux->prox == NULL) return 1; //lista vazia
    aux = aux->prox;

    puts("Lista:");
    while(aux->prox != NULL)
    {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("%d\n", aux->dado);
    return 0;
}