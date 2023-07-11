#include <stdio.h>
#define exch(A, B) {Item t = A; A = B; B = t;}
#define less(A, B) (A < B)

typedef int Item;

int partition(Item * v, int l, int r)
{
    Item pivot = v[r];
    int j = l;
    for(int k=l ; k < r ; k++) //o r nao inclui pois ele eh o pivot 
    {
        if(less(v[k], pivot))
        {
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]); // v[r] eh o pivot no vetor, poderia usar ponteiro para facilitar
    return j;
}

void quickSort(Item * v, int l, int r)
{
    int j = partition(v, l, r);
    if(r <= l) return;//caso base, quando ja esta ordenado
    quickSort(v, l, j-1);
    quickSort(v, j+1, r);
}