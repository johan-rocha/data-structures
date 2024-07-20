#include <stdio.h>

int main()
{
    double lines[1000], raio, pi = 3.14159;

    int i=0;
    while(scanf("%lf", &lines[i]) != EOF)
    {
        raio = lines[i];
        double area = pi * raio * raio;
        printf("%.4lf\n", area);
        i++;
    }
}