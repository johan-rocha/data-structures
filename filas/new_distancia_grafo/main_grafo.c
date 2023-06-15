#include "header.h"

int main()
{
    extern int dist[N];
    int A[N][N] = {{0, 1, 0, 0, 0, 0}, 
                   {0, 0, 1, 0, 0, 0}, 
                   {0, 0, 0, 0, 1, 0}, 
                   {0, 0, 1, 0, 1, 0}, 
                   {1, 0, 0, 0, 0, 0}, 
                   {0, 1, 0, 0, 0, 0}};

    distancias(A, 3);

    puts("As distancias de 3 as outras sao:\n");
    for(int l=0; l < N; ++l)
    {
        printf("%d ", dist[l]);
    }
    puts("");

}