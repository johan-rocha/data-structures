#include "header.h"

void divide_lista (celula *l, celula *l1, celula *l2) 
{
    celula *auxl = l->prox; // Ponteiro auxiliar para percorrer a lista l
    celula *auxSubs1 = l1; // Ponteiro auxiliar para adicionar nós em l1
    celula *auxSubs2 = l2; // Ponteiro auxiliar para adicionar nós em l2
    
    while(auxl != NULL) 
    { 
        // Percorre a lista l
        if(auxl->dado % 2 == 0) 
        { 
            // Se o número é par, adiciona em l2
            auxSubs2->prox = auxl;
            auxSubs2 = auxSubs2->prox;
        } 
        else 
        { 
            // Se o número é ímpar, adiciona em l1
            auxSubs1->prox = auxl;
            auxSubs1 = auxSubs1->prox;
        }
        auxl = auxl->prox; // Atualiza o ponteiro auxl
    }
    auxSubs1->prox = NULL; // Finaliza a lista l1
    auxSubs2->prox = NULL; // Finaliza a lista l2
    l = NULL; //Tira a referencia de l para os elementos
    
}