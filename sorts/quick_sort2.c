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