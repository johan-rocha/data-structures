#include <stdio.h>

typedef struct Coord
{
    int X, Y;
}Coord;

Coord move(Coord P, int Direction)
{
    switch (Direction)
    {
    case 1:
        P.Y++;
        return P;
    case 2:
        P.Y--;
        return P;
    case 3:
        P.X++;
        return P;
    case 4:
        P.X--;
        return P;
    default:
        break;
    }
}

int isInMicArea(Coord Mens, Coord Mic)
{
    
    for(int i=0; i < 5; i++)
    {
        
    }
}

int main()
{
    int N, M, K;
    Coord Mic, Mens;
    Mens.X = 0; Mens.Y = 0; 
    scanf("%d %d", &N, &M);
    scanf("%d %d", &Mic.X, &Mic.Y); 
    scanf("%d", &K);

    int direction, minutes = 0;
    for(int i=0; i<K; i++)
    {
        scanf("%d", &direction);
        Mens = move(Mens, direction);
        if(isInMicArea(Mens, Mic)) minutes++;
    }



}