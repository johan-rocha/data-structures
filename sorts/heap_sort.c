#include <stdio.h>

#define key(A) A
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if(less(B, A)) exch(A, B)
#define PAI(i) ((i-1)/2)
#define FILHO_ESQUERDO(i) (2*i+1)
#define FILHO_DIREITO(i) (2*i+2)

/***************************DATA STRUCTURES***************************/
typedef struct
{
    char nome[20];
    int chave;
}Item;

typedef struct
{
    Item * v;
    int n, tamanho;
}FP;

typedef FP * p_fp;
/*********************************************************************/

/***************************FUNC PROTOTYPES***************************/
p_fp criar_filaPrio(int tam);
void insere(p_fp fprio, Item dado);
Item extrai_maximo(p_fp fprio);
int vazia(p_fp fprio);
int cheia(p_fp fprio);
void fixUp(p_fp fprio, int k);
void fixDown(p_fp fprio, int k);
/*********************************************************************/


int main()
{


    return 0;
}

p_fp criar_filaPrio(int tam)
{
    p_fp fprio = malloc(sizeof(FP));
    fprio->v = malloc(tam * sizeof(Item));
    fprio->n = 0;
    fprio->tamanho = tam;
    return fprio;
}

void insere(p_fp fprio, Item dado)
{
    fprio->v[fprio->n] = dado;
    fprio->n++;
}

void fixUp(p_fp fprio, int k)
{
    if(k > 0 && fprio->v[PAI(k)].chave < fprio->v[k].chave)
    {
        exch(fprio->v[k], fprio->v[PAI(k)]);
    }
    fixUp(fprio, PAI(k));
}

Item extrai_maximo(p_fp fprio)
{
    Item dado = fprio->v[0];
    exch(fprio->v[0], fprio->v[fprio->n-1]);
    fprio->n--;


    int j, max = 0;
    for (j = 1; j < fprio->n; j++)
        if(fprio->v[max].chave < fprio->v[j].chave)
            max = j;

    exch(fprio->v[max], fprio->v[fprio->n-1]);
    fprio->n--;
    return fprio->v[fprio->n];

}

void fixDown(p_fp fprio, int k)
{
    int maior_filho;
    if(FILHO_ESQUERDO(k) < fprio->n )
}