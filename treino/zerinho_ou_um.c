#include <stdio.h>

int main()
{
    char a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a != b && a != c) //é possível (a != b -> F) e (a!=c -> V) e (b != c -> V)?
        puts("A");
    else if(b != a && b!=c)
    return 0;
}