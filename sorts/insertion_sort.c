#include <stdio.h>
#define exch(A, B) {Item t = A; A = B; B = t;}
#define less(A, B) (A < B)

typedef int Item;

void insertionSort(Item * v, int l, int r)
{
    for(int i=l; i<r; ++i)
        for(int j=i; j>l && less(v[j], v[j-1]); --j)
            exch(v[j], v[j-1]);
}

int main()
{
    int v[400], num, i = 0;
    while(scanf("%d", &num) != EOF)
    {
        v[i++] = num;
    }
    insertionSort(v, 0, 256);

    puts("\n\n");
    for(i = 0; i <= 256; ++i)
        printf("%d ", v[i]);
}