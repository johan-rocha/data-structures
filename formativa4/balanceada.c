#include <stdio.h>
#include <stdlib.h>

#define MAXN 5005

// Estrutura para representar a árvore binária usando listas de adjacência
typedef struct Node 
{
    int value;
    struct Node *next;
} Node;

Node *adj[MAXN]; // Lista de adjacência para os nós da árvore
int subtree_height[MAXN]; // Altura das subárvores de cada nó

// Função para calcular a altura de uma subárvore a partir de um nó
int calculate_height(int node) 
{
    Node *current = adj[node];
    int max_height = 0;
    int second_max_height = 0;

    // Percorre todos os filhos do nó atual
    while (current != NULL) 
    {
        int child = current->value;
        int height = calculate_height(child);
        
        // Atualiza a altura máxima e a segunda altura máxima
        if (height > max_height) 
        {
            second_max_height = max_height;
            max_height = height;
        } 
        else if (height > second_max_height) 
        {
            second_max_height = height;
        }

        current = current->next;
    }

    // Atualiza a altura da subárvore atual
    subtree_height[node] = 1 + max_height;

    // Retorna a altura da subárvore atual
    return subtree_height[node];
}

// Função para verificar se a árvore é balanceada
int is_balanced(int node) 
{
    Node *current = adj[node];
    int max_height = 0;
    int second_max_height = 0;

    // Percorre todos os filhos do nó atual
    while (current != NULL) 
    {
        int child = current->value;
        int height = subtree_height[child];

        // Atualiza a altura máxima e a segunda altura máxima
        if (height > max_height) 
        {
            second_max_height = max_height;
            max_height = height;
        } 
        else if (height > second_max_height) 
        {
            second_max_height = height;
        }

        // Verifica balanceamento recursivamente
        if (!is_balanced(child)) 
        {
            return 0;
        }

        current = current->next;
    }

    // Verifica a condição de balanceamento
    if (max_height - second_max_height > 1) 
    {
        return 0;
    }

    return 1;
}

int main() 
{
    int N;
    scanf("%d", &N);

    // Inicializa a lista de adjacência
    for (int i = 1; i <= N; ++i) 
    {
        adj[i] = NULL;
    }

    // Lê os nós pais
    int parent;
    for (int i = 2; i <= N; ++i) 
    {
        scanf("%d", &parent);
        
        // Adiciona i como filho de parent na lista de adjacência
        Node *child_node = (Node *)malloc(sizeof(Node));
        child_node->value = i;
        child_node->next = adj[parent];
        adj[parent] = child_node;
    }

    // Calcula a altura de toda a árvore a partir da raiz (nó 1)
    calculate_height(1);

    // Verifica se a árvore é balanceada a partir da raiz (nó 1)
    if (is_balanced(1)) 
    {
        printf("Sim\n");
    } 
    else 
    {
        printf("Nao\n");
    }

    return 0;
}
