#include <stdio.h>

typedef struct coordinates
{
    int x, y;
}coordinates;

int modulo(int n)
{
    if(n >= 0)
        return n;
    return -n;
}

int main()
{
    coordinates maria, reuniao;
    scanf("%d %d %d %d", &maria.x, &maria.y, &reuniao.x, &reuniao.y);
    printf("%d\n", modulo(reuniao.x-maria.x)+modulo(reuniao.y-maria.y));
    return 0;
}   