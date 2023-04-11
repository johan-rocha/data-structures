#include <stdio.h>

typedef struct coordinates
{
    int x, y;
}coordinates;

int main()
{
    coordinates maria, reuniao;
    scanf("%d %d %d %d", &maria.x, &maria.y, &reuniao.x, &reuniao.y);
    printf("%d\n", reuniao.x+reuniao.y-maria.x-maria.y);
    return 0;
}