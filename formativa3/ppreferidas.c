#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 65536 // Tamanho da tabela hash, suficientemente grande

// Definição da estrutura de um nó na tabela hash
typedef struct node {
    char word[17]; // String para armazenar a palavra (com espaço para o caractere nulo)
    int count; // Contagem de votos para a palavra
    struct node *next; // Próximo nó na lista encadeada (em caso de colisão)
} node;

// Função de hash simples usando o método de multiplicação
unsigned int hash(const char *str) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % TABLE_SIZE;
}

// Função para inserir uma palavra na tabela hash ou atualizar sua contagem de votos
void insert_or_update(node **hash_table, const char *word, int count) {
    unsigned int index = hash(word);
    node *current = hash_table[index];
    node *prev = NULL;

    // Procurar pela palavra na lista encadeada
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            // Palavra encontrada, atualizar a contagem de votos
            current->count = count;
            return;
        }
        prev = current;
        current = current->next;
    }

    // Palavra não encontrada, inserir no início da lista encadeada
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(new_node->word, word);
    new_node->count = count;
    new_node->next = NULL;

    if (prev == NULL) {
        // Lista estava vazia
        hash_table[index] = new_node;
    } else {
        // Adiciona ao final da lista encadeada
        prev->next = new_node;
    }
}

// Função para obter a contagem de votos de uma palavra
int get_count(node **hash_table, const char *word) {
    unsigned int index = hash(word);
    node *current = hash_table[index];

    // Procurar pela palavra na lista encadeada
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            // Palavra encontrada, retorna a contagem de votos
            return current->count;
        }
        current = current->next;
    }

    // Palavra não encontrada, retorna 0
    return 0;
}

// Função para remover uma palavra e sua contagem de votos da tabela hash
void remove_word(node **hash_table, const char *word) {
    unsigned int index = hash(word);
    node *current = hash_table[index];
    node *prev = NULL;

    // Procurar pela palavra na lista encadeada
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            // Palavra encontrada, remover da lista
            if (prev == NULL) {
                // Era o primeiro nó
                hash_table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Função para liberar a memória alocada para a tabela hash
void free_hash_table(node **hash_table) {
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

    char word[17];
    int command;
    while (scanf("%d %s", &command, word) != EOF) {
        switch (command) {
            case 1:
                // Adicionar mais um voto para a palavra
                insert_or_update(hash_table, word, get_count(hash_table, word) + 1);
                break;
            case 2:
                // Obter a contagem de votos da palavra
                printf("%d\n", get_count(hash_table, word));
                break;
            case 3:
                // Resetar a contagem de votos da palavra
                remove_word(hash_table, word);
                break;
            default:
                fprintf(stderr, "Comando inválido.\n");
                break;
        }
    }

    free_hash_table(hash_table);

    return 0;
}
