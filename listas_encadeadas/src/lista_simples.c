#include "header.h"

int main()
{
    char opcao = 1;
    celula * le = criar_lista();
    celula * l1 = criar_lista(); //a dividir
    celula * l2 = criar_lista(); //a dividir

    while(opcao != 0)
    {
        int temp;
        celula * temp_cell;

        puts("OPCAO (0): FECHAR O PROGRAMA\n"
             "OPCAO (1): INSERIR NA LISTA\n"
             "OPCAO (2): REMOVER DA LISTA\n"
             "OPCAO (3): IMPRIMIR LISTA\n"
             "OPCAO (4): BUSCAR NA LISTA POR ITERAÇAO\n"
             "OPCAO (5): BUSCAR NA LISTA POR RECURSAO\n"
             "OPCAO (6): DIVIDIR LISTA IMPAR/PAR");
        scanf("%hhd", &opcao);

        switch(opcao)
        {
            case 1:
                puts("INSIRA O VALOR QUE DESEJA INSERIR:");
                scanf("%d", &temp);
                inserir_na_lista(le, temp);
                break;
            case 2:
                puts("INSIRA O VALOR QUE DESEJA REMOVER:");
                scanf("%d", &temp);
                remover_da_lista(le, temp);
                break;
            case 3:
                printf("le = ");
                imprimir_lista(le);
                printf("l1 = ");
                imprimir_lista(l1);
                printf("l2 = ");
                imprimir_lista(l2);
                break;
            case 4:
                puts("INSIRA O VALOR QUE DESEJA BUSCAR:");
                scanf("%d", &temp);
                temp_cell = busca(le, temp);
                printf("o valor de sua celula eh: %d\n", temp_cell->dado);
                break;
            case 5:
                puts("INSIRA O VALOR QUE DESEJA BUSCAR:");
                scanf("%d", &temp);
                temp_cell = busca_rec(le, temp);
                printf("o valor de sua celula eh: %d\n", temp_cell->dado);
                break;
            case 6:
                divide_lista(le, l1, l2);
        }
    }

    free(le);
    free(l1);
    free(l2);
}