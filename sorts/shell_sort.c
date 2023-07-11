#include <stdio.h>
#define exch(A, B) {Item t = A; A = B; B = t;}

typedef int Item;

/* void shellSort(Item * v, int l, int r, int h)
{
    int h = 1;
    while(h < (r-l+1 /3)) h = 3*h+1;

    while(h>=1)
    {
        for(int i=l+h; i<=r; ++i)
        {
            for(int j=i; j>=l+h && v[j] < v[j-h]; )
            {
                exch(v[j], v[j-h]);
            }
            h = h/3;
        }
    }
} */


/* void shellSort(Item * v, int l, int r)
{
    int h = 1;
    while(h < (r-l+1)) h =3*h+1;

    while(h > 1)
    {
        for(int i=l+h; i<=r; ++i)
        {
            for(int j=i; j>=l+h; j-=h)
            {
                exch(v[j], v[j-h])
            }
        }
        h = h/3;
    }

} */