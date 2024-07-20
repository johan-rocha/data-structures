#include <stdio.h>
#define exch(A, B) {int t=A; A=B; B=t;}
#define cmpexch(A, B) {if(B < A) exch(A, B)}

static int separa(int v[], int p, int r)
{
    int pivot = v[r];
    int j = p;
    for(int k=p; k < r; k++)
        if(v[k] <= pivot)
        {
            exch(v[j], v[k]);
            j++;
        }

    exch(v[j], v[r]);
    return j;
}

void quickSort(int v[], int p, int r)
{
    if(p < r)
    {
        cmpexch(v[(p+r)/2], v[r])
        cmpexch(v[p], v[(p+r)/2])
        cmpexch(v[r], v[(p+r)/2])
        int j = separa(v, p, r);
        quickSort(v, p, j-1); 
        quickSort(v, j+1, r);
    }
}

int main()
{   
    int n;
    scanf("%d", &n);
    int vec[n];
    for(int i=0; i<n; i++)
        scanf("%d", &vec[i]);
    
    quickSort(vec, 0, (n-1));
    for(int i=0; i<n; i++)
        printf("%d ", vec[i]);
    puts("");


}