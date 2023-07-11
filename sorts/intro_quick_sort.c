#include <stdio.h>
#include <math.h>
#define exch(A, B) {Item t = A; A = B; B = t;}
#define less(A, B) (A < B)

typedef int Item;

static int problem; //for introsort

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

void quickSort(Item * v, int l, int r, int recursion)
{
    int j = partition(v, l, r);
    if(r - l < 32) return; //caso base, garante uma quase ordenacao para subvetores de 32 elementos, para que possa usar um algoritmo adaptativo. (alteracao p intro)
    if(recursion == 0) //para o introSort
    {
        problem = 1;
        return;
    } 
    quickSort(v, l, j-1, recursion - 1);
    quickSOrt(v, j+1, r, recursion - 1); //alteracao p intro
}

void insertionSort(int v[], int l, int r)
{
    for(int i=l+1; i<=r; i++)
    {
        for(int j=i; j>l && v[j]<v[j-1]; j--)
            exch(v[j], v[j-1]);
        //show(v, l, r);
    }
}

void shellSort(int v[], int l, int r)
{
    int h = 1;
    while(h < (r-l+1)/3) h = 3*h+1;

    while(h>=1){
        for(int i=l+h; i<=r; i++)
        {
            for(int j=i; j>=l+h && v[j]<v[j-h]; j-=h)
            {
                int a = v[j];
                v[j] = v[j-h];
                v[j-h] = a;
            }
        }
        h = h/3;
    }
}

void introSort(Item * v, int l, int r)
{
    int maxRecursion = 2*((int)log2((double)(r-l+1)));
    problem = 0;

    quickSort(v, l, r, maxRecursion);

    if(problem)
    {
        //roda outro algoritmo de ordenacao Nlog(N)
        //mergesort
        //heapsort
        //smoothsort
        shellSort(v, l, r);
    }
    else
    {
        //arruma a quase ordenacao com um algoritmo adaptativo (insertionSort)
        insertionSort(v, l, r);
    }
}