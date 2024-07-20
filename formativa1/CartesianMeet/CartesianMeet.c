#include <stdio.h>
#include <stdlib.h>

typedef struct Coord
{
    int x;
    int y;
}Coord;

Coord move(Coord P, int Direction)
{
    switch (Direction)
    {
    case 1:
        P.y++;
        return P;
    case 2:
        P.y--;
        return P;
    case 3:
        P.x++;
        return P;
    case 4:
        P.x--;
        return P;
    default:
        break;
    }
}

int isNotInLimitCoord(Coord P, int N, int M)
{
    if(P.x < 1 || P.y < 1) return 1;
    if(P.x > N || P.y > M) return 1;
    return 0;
}

int isEqualCoord(Coord Pa, Coord Pb)
{
    if(Pa.x == Pb.x && Pa.y == Pb.y) return 1;
    return 0;
}

int main()
{
    int N, M, P;
    scanf("%d %d\n%d", &N, &M, &P);


    Coord PA, PB;
    PA.x = 1; PA.y = 1;
    PB.x = N; PB.y = M;

    int A, B, i;
    for(i=1; i <= P; i++)
    {
        scanf("%d %d", &A, &B);
        PA = move(PA, A);
        PB = move(PB, B);

        if(isNotInLimitCoord(PA, N, M))
        {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", PA.x, PA.y, i);
            break;
        }
        if(isNotInLimitCoord(PB, N, M))
        {
            printf("PB saiu na posicao (%d,%d) no passo %d\n", PB.x, PB.y, i);
            break;
        }
        if(isEqualCoord(PA, PB))
        {
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", PA.x, PA.y, i);
            break;
        }
    }
    if(i > P)
        puts("Nao se encontraram");

}