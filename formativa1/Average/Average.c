#include <stdio.h>

int average(int v[], int size)
{
    int sum = 0;
    for(int i=0; i < size; i++)
        sum += v[i];
    
    return (sum/size);
}

void showBiggerThan(int ref, int values[], int values_size)
{
    int bigger_than_index = 0, bigger_than[values_size], i;
    for(i=0; i < values_size; i++)
        if(values[i] > ref)
        {
            bigger_than[bigger_than_index] = values[i];
            bigger_than_index++;
        }
    
    if(bigger_than_index == 0)
        printf("0\n");
    else
    {
        for(i=0; i < (bigger_than_index - 1); i++)
            printf("%d ", bigger_than[i]);
        printf("%d\n", bigger_than[i]);
    }
}

int main()
{
    int size;
    scanf("%d", &size);
    int values[size];
    for(int i=0; i < size; i++)
        scanf("%d", &values[i]);
    showBiggerThan(average(values, size), values, size);
}