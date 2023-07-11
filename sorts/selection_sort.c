#include <stdio.h>
#define less(A, B) (A < B)
#define exch(A, B) {Item t = A; A = B; B = t;}

typedef int Item;

void selectionSortRecursive(Item * v, int l, int r)
{
    if(l == r)
        return;

    int index_menor = l;
    for(int i=l+1; i<=r; ++i)
    {
        if(less(v[i], v[index_menor]))
            index_menor = i;
    }
    exch(v[l], v[index_menor]);
    selectionSortRecursive(v, l+1, r);

}

 void selectionSortLoop(Item * v, int l, int r)
{
    int index_menor;
    for(int j=l; j<=r; ++j)
    {
        index_menor = j;
        for(int i=j+1; i<=r; ++i)
        {
            if(less(v[i], v[index_menor]))
                index_menor = i;
        }
        exch(v[j], v[index_menor]);
    }
}


int main()
{
    int v[67000], num, i = 0;
    while(scanf("%d", &num) != EOF)
    {
        v[i++] = num;
    }
    selectionSortLoop(v, 0, 65536);

    puts("\n\n");
    for(i = 0; i <= 256; ++i)
        printf("%d ", v[i]);
}