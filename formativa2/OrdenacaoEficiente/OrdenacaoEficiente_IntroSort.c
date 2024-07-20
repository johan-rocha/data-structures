#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(B<A) exch(A,B)}


static int separa(int v[], int p, int r)
{
    int pivot = v[r];
    int j=p;

    for(int k=p; k < r; k++)
    {
        if(v[k] <= pivot)
        {
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]);
    return j;
}

int quickSortM3(int v[], int p, int r, int max_rec)
{
    if(max_rec == 0)
        return 0;
    if(r-p > 32)
    {
        cmpexch(v[(p+r)/2], v[r]);
        cmpexch(v[p], v[(p+r)/2]);
        cmpexch(v[r], v[(p+r)/2]);
        int i = separa(v, p, r);
        quickSortM3(v, p, (i-1), (max_rec-1));
        quickSortM3(v, (i+1), r, (max_rec-1));
    }
    return 1;
}

static void intercala(int v[], int p, int r1, int r2)
{
    int * v2 = malloc(sizeof(int) * (r2-p+1));

    int k=0;
    int i=p;
    int j=(r1+1);

    while(i <= r1 && j <= r2)
    {
        if(v[i] < v[j])
            v2[k++] = v[i++];
        else
            v2[k++] = v[j++];
    }     
    while(i <= r1) v2[k++] = v[i++];
    while(j <= r2) v2[k++] = v[j++];

    for(i=p, k=0; i<=r2; i++, k++)
        v[i] = v2[k];
    
    free(v2);


}

void mergeSort(int v[], int p, int r)
{
    if(p < r)
    {
        int meio = (r+p)/2;
        mergeSort(v, p, meio);
        mergeSort(v, (meio+1), r);
        intercala(v, p, meio, r);
    }
}

void insertionSort(int v[], int p, int r)
{

    for(int i=r; i>p; i--)
        cmpexch(v[i-1], v[i]);

    for(int i=p+2; i<=r; i++)
    {
        int j=i, tmp=v[i];
        while(tmp<v[j-1])
        {
            v[j]=v[j-1];
            j--;
        }
        v[j]=tmp;
    }         
}

void introSort(int v[], int p, int r)
{
    int max_rec=2*log2((r-p+1));
    if(!quickSortM3(v, p, r, max_rec))
        mergeSort(v, p, r);
    else
        insertionSort(v, p, r);
}

int main()
{   
    int n;
    scanf("%d", &n);
    int vec[n];
    for(int i=0; i<n; i++)
        scanf("%d", &vec[i]);
    
    introSort(vec, 0, (n-1));
    for(int i=0; i<n; i++)
        printf("%d ", vec[i]);
    puts("");


}