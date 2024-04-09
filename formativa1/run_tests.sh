#!/bin/bash

# Nome do programa compilado
PROGRAMA="./Average.c"
chmod +x "$PROGRAMA"

# Arquivo de testes
ARQUIVO_TESTES="input.txt"

# Loop para ler cada linha do arquivo de testes
while IFS= read -r input; do
    # Executa o programa com o input atual e captura a saída
    output=$($PROGRAMA <<< "$input")

    # Lê a saída esperada do arquivo de testes
    expected_output=$(echo "$input" | awk '{print $1 * 2}')

    # Compara a saída do programa com a saída esperada
    if [ "$output" = "$expected_output" ]; then
        echo "Teste para entrada '$input' passou!"
    else
        echo "Teste para entrada '$input' falhou. Saída obtida: $output. Saída esperada: $expected_output"
    fi
done < "$ARQUIVO_TESTES"
