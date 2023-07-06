#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define key(A) A
#define less(A, B) (A < B)
#define exch(A, B) {Item t = A; A = B; B = t;}
#define compexch(A, B) if(less(A, B)) exch(A, B)
#define DAD(i) (i/2)
#define L_CHILD(i) (2*i)
#define R_CHILD(i) (2*i+1)
typedef int Item;


static Item * pq;
static int N;

void show(int v[], int l, int r)
{
    for(int i = l; i <= r; ++i)
        printf("%d ", v[i]);
    puts("");
}

int is_sorted(int v[], int l, int r)
{
    int p;
    for(p = r; p > l && v[p-1] <= v[p]; --p);

    return (p == 0);
}

void PQinit(int maxN)
{
    pq = malloc(sizeof(Item) * maxN);
    N = 0;
}

int PQempty()
{
    return (N == 0);
}

void fixUp(int k)
{
    while(k > 1 && less(pq[DAD(k)], pq[k])) // k > 1 (o zero eh desconsiderado, entao a raiz fica no 1) e se o pai eh menor do que o filho
    {
        exch(pq[DAD(k)], pq[k]);
        k = DAD(k);
    }
}

void fixDown(int k, int N)
{
    int j;
    while(L_CHILD(k) < N)
    {
        //j tem que receber o maior dos filhos
        j = less(L_CHILD(k), R_CHILD(k)) ? R_CHILD(k) : L_CHILD(k);

        //se o pai nao for menor que o maior dos filhos, para
        if(!less(pq[k], pq[j])) break;

        //senao, afunde
        exch(pq[k], pq[j]);
        k = j;
    }
}

void PQinsert(Item v)
{
    pq[++N] = v;
    fixUp(N);
}

Item PQdelmax()
{
    //troque topo -> ultimo
    exch(pq[1], pq[N]);

    //reposicione o ultimo que esta no topo
    fixDown(1, N-1);

    //retorna o maximo
    return pq[N--];
}

void PQsort(Item * v, int l, int r)
{
    PQinit(r-l+1);
    for(int k = l; k <= r; ++k)
    {
        PQinsert(v[k]);
    }
    for(int k = r; k >= l; k--)
    {
        v[k] = PQdelmax();
    }
}

void heap_sort(Item * v, int l, int r)
{
    pq = v+l-1;
    N = r-l+1;
    for(int k = DAD(N); k >=1; k--)
    {
        fixDown(k, N);
    }
    while(N > 1)
    {
        exch(pq[1], pq[N]);
        fixDown(1, --N);
    }
}