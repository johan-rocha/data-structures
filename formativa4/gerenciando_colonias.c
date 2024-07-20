#include <stdio.h>
#include <string.h>

#define MAX_COLONIES 1048576 // 2^20

int main() {
    int estoque[MAX_COLONIES]; // Vetor para controlar o estoque por identificação de colônia
    char alimento[12]; // String para armazenar o tipo de alimento
    int id_colonia;

    // Inicializar vetor de estoques com 0 (nenhum alimento entregue inicialmente)
    memset(estoque, 0, sizeof(estoque));

    while (scanf("%d %s", &id_colonia, alimento) != EOF) {
        if (estoque[id_colonia] == 0) {
            // Nenhum alimento registrado para essa colônia
            estoque[id_colonia] = 1; // Registrar o alimento entregue
        } else {
            // Já existe um alimento registrado para essa colônia
            printf("%d\n", id_colonia);
        }
    }

    return 0;
}
