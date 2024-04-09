#include <stdio.h>
#include <stdlib.h>

void showTheater(char v[][25], int line_size, int column_size)
{
    int i, j;

    printf("  ");
    for(i = 1; i <= column_size; i++)
        printf("%02d ", i);
    puts("");

    for(i= (line_size - 1); i >= 0; i--)
    {
        printf("%c ", (char) i + 'A');
        for(j=0; j < (column_size-1); j++)
            printf("%s ", (v[i][j] == 1) ? "XX": "--");
        printf("%s\n", (v[i][j] == 1) ? "XX": "--");
    }
}

int main()
{
    int F, L;
    scanf("%d %d\n", &F, &L);

    //create matrix
    char theather[20][25] = {};

    char chosen_F; int chosen_L;
    while(scanf("%c%d", &chosen_F, &chosen_L) != EOF)
    {
        getchar();
        chosen_F -= 'A'; //convert to index
        chosen_L -= 1 ; //convert to index
        theather[chosen_F][chosen_L] = 1;
    }

    showTheater(theather, F, L);
}