#include <stdio.h>
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(B<A) exch(A,B)}

int separa(int v[], int p, int r)
{
    int pivot = v[r];
    int j = p;

    for(int k=p; k < r; k++)
    {
        if(v[k]<=pivot)
        {
            exch(v[j],v[k]);
            j++;
        }
    }
    exch(v[j], v[r]); //nao pode ser trocado pela variavel pivot pois o que se precisa eh alterar a posicao v[r], nao a variavel pivot
    return j;
}

void quickSelect(int v[], int p, int r, int k)
{
    if(p < r)
    {
        int i = separa(v, p, r);
        if(i > k) quickSelect(v, p, (i-1), k);
        if(i < k) quickSelect(v, (i+1), r, k);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int vec[n];
    for(int i=0; i<n; i++)
        scanf("%d", &vec[i]);
    
    quickSelect(vec, 0, (n-1), 0);
    for(int i=0; i<n; i++)
        printf("%d ", vec[i]);

    puts("");

}