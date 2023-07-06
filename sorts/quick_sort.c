#include <stdio.h>
#include <stdlib.h>
#define exch(A, B) {Item t = A; A = B; B = t}
#define less(A, B) (A < B)

typedef int Item;

int partition(Item * v, int r, int l)
{
    int tam = r-l+1; Item pivot = v[r];
    Item * menores = malloc(tam * sizeof(Item));
    Item * maiores = malloc(tam * sizeof(Item));

    int tamMenor = 0, tamMaior = 0;

    for(int i=l; i<r; ++i) //por que nao <= r ? por que o pivot vai ser o ultimo?
    {
        if(less(v[i], pivot))
            menores[tamMenor++] = v[i];
        else
            maiores[tamMaior++] = v[i];
    }
    int i = l; //o i conta o indice do vetor v, enquanto os j contam o indice dos subvetores

    for(int j=0; j<tamMenor; ++j) //coloca os menores no vetor v
        v[i++] = menores[j]; 

    v[i] = pivot; //coloca o pivot depois dos menores
    int pivotPos = i; //guarda a posicao do pivot
    
    i++;
    for(int j=0; j<tamMaior; ++j) //coloca os maiores no vetor v
        v[i++] = maiores[j];

    free(maiores); free(menores);
    return pivotPos;
}


