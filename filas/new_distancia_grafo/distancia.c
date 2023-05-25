#include "header.h"
int fila[N];
int p, u;

void cria_fila()
{
    p = u = 0;
}

int dequeue()
{
    int elemento = fila[p];
    p = (p + 1) % N;
    return elemento;

    /*MODO 2
    int elemento = fila[p++];
    if(p == N) p = 0;
    return elemento
    */
}

void enqueue(int y)
{
    fila[u] = y;
    u = (u + 1) % N;

    /*MODO 2
    fila[u++] = y;
    if(u == N) u = 0;
    */
}

int fila_vazia()
{
    if(u == p)
        return 1;
    else
        return 0;

}

int fila_cheia()
{
    if((u + 1) % N == p)
        return 1;
    else
        return 0;
}

int fila_comprimento()
{
    return p - u;

    if(u < p)
        return N - (p - (u+1))
}