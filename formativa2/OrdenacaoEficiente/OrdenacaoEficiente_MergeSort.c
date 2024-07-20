#include <stdio.h>
#include <stdlib.h>

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


int main()
{   
    int n;
    scanf("%d", &n);
    int vec[n];
    for(int i=0; i<n; i++)
        scanf("%d", &vec[i]);
    
    mergeSort(vec, 0, (n-1));
    for(int i=0; i<n; i++)
        printf("%d ", vec[i]);
    puts("");


}