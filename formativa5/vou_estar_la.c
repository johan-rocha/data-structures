#include <stdio.h>
#include <stdlib.h>

typedef struct grafo
{
    int ** adj;
    int n;
} * p_grafo;

p_grafo criar_grafo(int n);
void destroi_grafo(p_grafo g);
void insere_aresta(p_grafo g, int u, int v);
void remove_aresta(p_grafo g, int u, int v);
int tem_aresta(p_grafo g, int u, int v);
void imprime_arestas(p_grafo g);

p_grafo criar_grafo(int n)
{
    p_grafo g = malloc(sizeof(struct grafo));
    g->n = n;
    g->adj = malloc(n*sizeof(int *));
    for(int i=0; i<n; i++)
        g->adj[i] = calloc(n, sizeof(int));
    return g;
}

void destroi_grafo(p_grafo g)
{
    for(int i=0; i<g->n; i++)
        free(g->adj[i]);
    free(g->adj);
    free(g);
}

void insere_aresta(p_grafo g, int u, int v)
{
    g->adj[u][v]=1;
    g->adj[v][u]=1;
}

void remove_aresta(p_grafo g, int u, int v)
{
    g->adj[u][v]=0;
    g->adj[v][u]=0;
}

int tem_aresta(p_grafo g, int u, int v)
{
    return g->adj[u][v];
}

void marca_onde_estara(p_grafo g, int u)
{
    for(int i=0; i<g->n; i++)
    {
        if(g->adj[u][i])
        {
            g->adj[u][i]=2;
            g->adj[i][u]=2;
        }
    }
}

int main()
{
    p_grafo g;
    int N, M, J, i, j;
    scanf("%d %d %d", &N, &M, &J);
    g = criar_grafo(N);
    /* 
    N -> Numero de locais do bairro
    M -> Numero de locais em que juliano já esteve
    J -> Numero de locais que deseja-se saber se Juliano estará

    todos os locais são enumerados entre 0 e N
     */
    int A, vizinho;
    for(i=0; i<N; i++)
    {
        scanf("%d", &A);
        for(j=0; j<A; j++)
        {
            scanf("%d", &vizinho);
            insere_aresta(g, i ,vizinho);
        }
    }

    int esteve;
    for(i=0; i<M; i++)
    {
        scanf("%d", &esteve);
        marca_onde_estara(g, esteve);
    }

    int estara;
    for(i=0; i<J; i++) //verifica se estara
    {
        scanf("%d", &estara);
        if(g->adj[estara][]==2)
            puts("Eu vou estar la");
        else
            puts("Nao vou estar la");
    }

    destroi_grafo(g);
}