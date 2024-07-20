#include <stdio.h>
#include <stdlib.h>

void intercala(int v[], int p, int r1, int r2)
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

int main()
{
    int * v = malloc(sizeof(int));
    int size_vector=0;
    for(int k=0; k<8; k++)
    {
        int S;
        scanf("%d", &S);
        size_vector+=S;
        v = realloc(v, sizeof(int)*size_vector);
        for(int i=(size_vector-S); i<size_vector; i++)
            scanf("%d", &v[i]);
        intercala(v, 0, (size_vector-S-1), (size_vector-1));
    }

    for(int i=0; i<size_vector-1; i++)
        printf("%d ", v[i]);
    printf("%d\n", v[size_vector-1]);
    

    free(v);
}