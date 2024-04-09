#include <stdio.h>

int Sum(int a, int b)
{
    return (a + b);
}

int main()
{
    int x, y;

    scanf("%d\n%d", &x, &y);
    printf("%d\n", Sum(x, y));
}