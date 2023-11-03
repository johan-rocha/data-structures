#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula * prox;
}celula;

typedef struct
{
    celula * tb; //tabela hash
    int M; //tamanho da tabela hash
    int N; //total de chaves presentes na tabela
}TH;

void THinsere(TH * h, int ch);
void inserirLista(celula * lista, int ch);
int THremove(TH * h, int ch);
void removerLista(celula * lista, int ch);
int THbusca(TH * h, int ch);
int achaNaLista(celula * lista, int ch);
int funcaoHash(TH * lista, int chave);

void THinsere(TH * h, int ch)
{
    int index_lista = funcaoHash(h, ch);
    inserirLista(&(h->tb[index_lista]), ch);
    h->N++;

}

void inserirLista(celula * lista, int ch)
{
    celula * new = malloc(sizeof(celula));
    
    if(new)
    {
        new->dado = ch;
        new->prox = lista->prox;
        lista->prox = new;
    }
    else
        abort();
}

int THremove(TH * h, int ch)
{
    int index_lista = funcaoHash(h, ch);
    if(THbusca(h, ch) == 1) // encontrada e removida
    {
        removerLista(&(h->tb[index_lista]), ch);
        return 0;
    }
    else //nao achou
        return -1;
}

void removerLista(celula * lista, int ch)
{
    celula * aux;        
    while(lista->prox->dado != ch)
        lista = lista->prox;
    
    aux = lista->prox;
    lista->prox = lista->prox->prox;
    free(aux);
    return 0;
}

int THbusca(TH * h, int ch)
{
    int i = 0;
    while(!achaNaLista(&(h->tb[i]), ch) && i < h->M)i++;

    if(i >= h->M)
        return 0; //nao encontrou
    else
        return 1;  //encontrou
}

int achaNaLista(celula * lista, int ch)
{
    while(lista != NULL)
    {
        if(lista->dado == ch)
            return 1;
        lista = lista->prox;
    }
    return 0;
}

int funcaoHash(TH * dados_tabela, int chave)
{
    return chave % dados_tabela->M;
}   