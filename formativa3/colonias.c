#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 2000003 // Usar um número primo maior para melhor distribuição

typedef struct node {
    char colony[12]; // String para armazenar o identificador da colônia
    char food[12]; // String para armazenar o tipo de alimento
    struct node *next;
} node;

unsigned int hash(const char *str) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % TABLE_SIZE;
}

void insere_tabela(node **hash_table, const char *colony, const char *food) {
    unsigned int index = hash(colony);
    node *current = hash_table[index];

    // Procurar se o item já existe na lista
    while (current != NULL) {
        if (strcmp(current->colony, colony) == 0 && strcmp(current->food, food) == 0) {
            printf("%s\n", colony); // Se já existe, imprime o identificador da colônia
            return;
        }
        current = current->next;
    }

    // Se não encontrado, adiciona à tabela
    node *novo = malloc(sizeof(node));
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(novo->colony, colony);
    strcpy(novo->food, food);
    novo->next = hash_table[index];
    hash_table[index] = novo;
}

void libera_tabela(node **hash_table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        node *current = hash_table[i];
        while (current != NULL) {
            node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hash_table);
}

int main() {
    node **hash_table = calloc(TABLE_SIZE, sizeof(node *));
    if (hash_table == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a tabela hash.\n");
        return 1;
    }

    char colony[12];
    char food[12];

    while (scanf("%s %s", colony, food) != EOF) {
        insere_tabela(hash_table, colony, food);
    }

    libera_tabela(hash_table);

    return 0;
}
