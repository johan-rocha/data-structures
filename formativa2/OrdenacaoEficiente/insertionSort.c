#include <stdio.h>
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(B<A) exch(A,B)}

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

int main()
{   
    int n;
    scanf("%d", &n);
    int vec[n];
    for(int i=0; i<n; i++)
        scanf("%d", &vec[i]);
    
    insertionSort(vec, 0, (n-1));
    for(int i=0; i<n; i++)
        printf("%d ", vec[i]);
    puts("");


}