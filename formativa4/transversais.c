#include <stdio.h>
#include <string.h>

void pos_ordem(char* pre_ordem, char* em_ordem, int n, char* result, int* index) 
{
    if (n <= 0) 
    {
        return;
    }

    // A raiz é o primeiro elemento no percurso pré-fixo
    char root = pre_ordem[0];

    // Encontrar a posição da raiz no percurso infixo
    int rootIndex;
    for (rootIndex = 0; rootIndex < n; rootIndex++) 
    {
        if (em_ordem[rootIndex] == root) 
        {
            break;
        }
    }

    // Recursivamente, reconstruir a sub-árvore esquerda
    pos_ordem(pre_ordem + 1, em_ordem, rootIndex, result, index);
    // Recursivamente, reconstruir a sub-árvore direita
    pos_ordem(pre_ordem + 1 + rootIndex, em_ordem + rootIndex + 1, n - rootIndex - 1, result, index);

    // Adicionar a raiz ao resultado pós-fixo
    result[(*index)++] = root;
}

int main() 
{
    int C;
    scanf("%d", &C);

    for (int i = 0; i < C; i++) 
    {
        int N;
        char pre_ordem[53], em_ordem[53];
        scanf("%d %s %s", &N, pre_ordem, em_ordem);

        char result[53];
        int index = 0;
        pos_ordem(pre_ordem, em_ordem, N, result, &index);
        result[index] = '\0';

        printf("%s\n", result);
    }

    return 0;
}
