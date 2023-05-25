#include "header.h"
int  p, u;
int fila[N];
int dist[N];

void cria_fila(void)
{
    p = u = 0;
}

int fila_vazia(void)
{
    return p >= u;
}

int dequeue(void)
{
    return fila[p++];
}

void enqueue(int y)
{
    fila[u++] = y;
}



void distancias(int A[][N], int c)
{
    for(int j=0; j < N; ++j) dist[j] = N;
    dist[c] = 0;

    cria_fila();
    enqueue(c);

    while(!fila_vazia())
    {
        int i = dequeue();
        for(int j=0;  j < N; ++j)
        {
            if(A[i][j] == 1 && dist[j] >= N)
            {
                dist[j] = dist[i] + 1;
                enqueue(j);
            }
        }
    }
    

}