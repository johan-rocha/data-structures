#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    double value;
    int i,j;
}item;

static void intercala(item v[], int p, int r1, int r2)
{
    item * v2 = malloc(sizeof(item) * (r2-p+1));

    int k=0;
    int i=p;
    int j=(r1+1);

    while(i <= r1 && j <= r2)
    {
        if(v[i].value >= v[j].value)
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

void mergeSort(item v[], int p, int r)
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
    int T;
    scanf("%d", &T);
    for(int k=0; k<T; k++)
    {
        int M, N;
        scanf("%d\n%d", &M, &N);
        int vector_size=M*N;
        item vec[vector_size];
        int count=0;
        for(int i=1; i<=M; i++)
            for(int j=1; j<=N; j++)
            {
                scanf("%lf", &vec[count].value);
                vec[count].i=i;
                vec[count++].j=j;
            }
        mergeSort(vec, 0, (vector_size-1));

        
        //for(int i=0; i<(vector_size-1); i++)
        //    printf("%lf ", vec[i].value);
        //printf("%lf\n", vec[(vector_size-1)].value);

        
        for(int i=0; i<(vector_size-1); i++)
            printf("%d,%d ", vec[i].i, vec[i].j);
        printf("%d,%d\n", vec[(vector_size-1)].i, vec[(vector_size-1)].j);

    }


}