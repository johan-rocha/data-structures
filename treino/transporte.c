#include <stdio.h>

int quantoCabe(int objeto,int eixo)
{
    return (eixo/objeto);
}

int main()
{
    int a, b, c, x, y, z;
    scanf("%d %d %d\n%d %d %d", &a, &b, &c, &x, &y, &z);
    printf("%d\n", quantoCabe(a, x)*quantoCabe(b,y)*quantoCabe(c,z));

    return 0;
}