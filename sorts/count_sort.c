#include <stdio.h>
#include <stdlib.h>
#define less(A, B) ((A) < (B))
//#define exch(A, B) {Item t = A; A = B; B = t;}

typedef int Item;

void countSort(Item v[], int l, int r)
{
    int tam;
    for(int i=l; i<=r; ++i)
    {
        if(v[i] > tam) //pega o maior numero
            tam = v[i];
    }
    tam += 2; //compensar o indice 0 e adicionar uma posicao relativa

    int * count = calloc(tam, sizeof(int)); //cria o vetor inicializado com 0
    for(int i=l; i<=r; ++i) //conta no vetor count
        count[v[i] + 1]++; //soma no proximo (posicao relativa)

    for(int i=1; i<tam; ++i) //soma o atual com o anterior no vetor count
        count[i] += count[i-1];

    Item * aux = malloc(sizeof(Item) * (r-l+1));
    for(int i=l; i<=r; ++i)
    {
       aux[count[v[i]]] = v[i];
       count[v[i]]++;
    }

    //passando o auxiliar para v
    for(int i=l; i < r; ++i)
        v[i] = aux[i - l]; //aux eh um vetor relativo

    free(aux);
}

int main()
{

}