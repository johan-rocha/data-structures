#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    long long key;
    int quantity;
    struct node *next;
} node;

unsigned int hash(long long key, int table_size) {
    return (unsigned int)((key % table_size + table_size) % table_size);  // Garantir índice não negativo
}

void insere_tabela(node **hash_table, long long key, int quantity, int table_size) {
    unsigned int index = hash(key, table_size);
    node *current = hash_table[index];
    node *prev = NULL;

    // Procurar se o item já existe na lista
    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        // Item já existe
        current->quantity += quantity;
        if (current->quantity <= 0) {
            // Remover item se a quantidade é menor ou igual a zero
            if (prev == NULL) {
                hash_table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
        }
    } else {
        // Item não existe, adicionar se a quantidade é positiva
        if (quantity > 0) {
            node *novo = malloc(sizeof(node));
            if (novo == NULL) {
                fprintf(stderr, "Erro ao alocar memória.\n");
                exit(1);
            }
            novo->key = key;
            novo->quantity = quantity;
            novo->next = hash_table[index];
            hash_table[index] = novo;
        }
    }
}

void libera_tabela(node **hash_table, int table_size) {
    for (int i = 0; i < table_size; i++) {
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
    int N;
    scanf("%d", &N);

    int table_size = 1279; // Tamanho da tabela hash
    node **hash_table = calloc(table_size, sizeof(node *));
    if (hash_table == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a tabela hash.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        long long K;
        int Q;
        scanf("%lld %d", &K, &Q);
        insere_tabela(hash_table, K, Q, table_size);
    }

    int total_items = 0;
    for (int i = 0; i < table_size; i++) {
        node *current = hash_table[i];
        while (current != NULL) {
            total_items += current->quantity;
            current = current->next;
        }
    }

    printf("%d\n", total_items);

    libera_tabela(hash_table, table_size);

    return 0;
}
