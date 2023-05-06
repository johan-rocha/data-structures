#include <stdio.h>

int main()
{
    int L, D, K, P, valor_total;
    scanf("%d %d\n%d %d", &L, &D, &K, &P);

    valor_total = (L/D)*P + K*L;
    printf("%d\n", valor_total);
    return 0;
}