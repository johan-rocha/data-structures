#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *prox;
} node;

void insere_fim_lista(node *head, int value) {
    while (head->prox != NULL) {
        head = head->prox;
    }

    node *novo = malloc(sizeof(node));
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }
    novo->value = value;
    novo->prox = NULL;
    head->prox = novo;
}

int fhash(int x, int vec_size) {
    return x % vec_size;
}

void insere_tabela(node **hash_table, int value, int vec_size) {
    int index = fhash(value, vec_size);
    insere_fim_lista(hash_table[index], value);
}

void printList(node *head, int index) {
    printf("%d -> ", index);
    while (head->prox != NULL) {
        printf("%d -> ", head->prox->value);
        head = head->prox;
    }
    printf("\\\n");
}

void printHash(node **hash_table, int vec_size) {
    for (int i = 0; i < vec_size; i++) {
        printList(hash_table[i], i);
    }
}

int main() {
    int N, M, C;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &M, &C);
        node **thash = calloc(M, sizeof(node *));
        if (thash == NULL) {
            fprintf(stderr, "Erro ao alocar memória para a tabela hash.\n");
            return 1;
        }

        // Inicializa cada entrada da tabela hash com um nó de cabeçalho
        for (int j = 0; j < M; j++) {
            thash[j] = malloc(sizeof(node));
            if (thash[j] == NULL) {
                fprintf(stderr, "Erro ao alocar memória para o nó de cabeçalho.\n");
                return 1;
            }
            thash[j]->prox = NULL;  // O cabeçalho inicialmente não aponta para nenhum nó
        }

        int x;
        for (int j = 0; j < C; j++) {
            scanf("%d", &x);
            insere_tabela(thash, x, M);
        }

        printHash(thash, M);
        puts("");

        // Libera a memória alocada para a tabela hash
        for (int j = 0; j < M; j++) {
            node *current = thash[j];
            while (current != NULL) {
                node *temp = current;
                current = current->prox;
                free(temp);
            }
        }
        free(thash);
    }
    return 0;
}
