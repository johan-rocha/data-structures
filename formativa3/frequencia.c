#include <stdio.h>
#include <stdlib.h>

#define ASCII_RANGE 95 // 127 - 32

int main() {
    int frequencies[ASCII_RANGE] = {0}; // Inicializa todas as frequências como 0
    char c;

    // Ler os caracteres e calcular suas frequências
    while (scanf("%c", &c) != EOF) {
        if (c >= 32 && c < 127) { // Verifica se o caractere está dentro do intervalo ASCII válido
            frequencies[c - 32]++; // Ajusta o índice do array de acordo com a posição na tabela ASCII
        }
    }

    // Imprimir os caracteres e suas frequências na ordem solicitada
    for (int i = 1; i <= ASCII_RANGE; i++) {
        int max_freq = 0;
        char max_char = 0;
        // Encontrar o caractere com a maior frequência
        for (int j = 0; j < ASCII_RANGE; j++) {
            if (frequencies[j] > max_freq) {
                max_freq = frequencies[j];
                max_char = j + 32; // Ajusta o caractere de volta para seu valor ASCII original
            }
        }
        // Se a frequência máxima for 0, todos os caracteres já foram impressos
        if (max_freq == 0) {
            break;
        }
        // Imprimir o caractere com sua frequência
        printf("%d %d\n", max_char, max_freq);
        // Definir a frequência do caractere impresso como 0 para que ele não seja impresso novamente
        frequencies[max_char - 32] = 0;
    }

    return 0;
}
