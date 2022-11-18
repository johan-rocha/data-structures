#include <stdio.h>
#define size 4
int bigger_insertion_sort(int vec[]);

int main()
{
    int vec[4];
    
    scanf("%d %d %d %d", &vec[0], &vec[1], &vec[2], &vec[3]);
    printf("%d\n", bigger_insertion_sort(vec));
    return 0;
}

int bigger_insertion_sort(int vec[])
{
    int i, j, aux;
    for(i = 1; i < size; i++)
    {
        aux = vec[i];
        for(j = i - 1; (j >= 0) && (aux < vec[j]); j--)
        {
            vec[j + 1] = vec[j];
        }
        vec[j+1] = aux;
    }
    return vec[3];
}
