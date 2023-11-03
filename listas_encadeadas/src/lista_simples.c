#include "header.h"

int main()
{
    short int opcao = 1;
    short int op_sec;
    celula * le = criar_lista();
    celula * l1 = criar_lista(); //a dividir
    celula * l2 = criar_lista(); //a dividir

    while(opcao != 0)
    {
        int temp, temp2;
        celula * temp_cell;

        puts("OPCAO (0): FECHAR O PROGRAMA\n"
             "OPCAO (1): INSERIR NA LISTA\n"
             "OPCAO (2): INSERIR ANTES DE\n"
             "OPCAO (3): REMOVER DA LISTA\n"
             "OPCAO (4): IMPRIMIR LISTA\n" 
             "OPCAO (5): IMPRIMIR LISTA RECURSIVA\n"
             "OPCAO (6): BUSCAR NA LISTA POR ITERAÇAO\n"
             "OPCAO (7): BUSCAR NA LISTA POR RECURSAO\n"
             "OPCAO (8): DIVIDIR LISTA IMPAR/PAR\n"
             "OPCAO (9): MESCLAR LISTAS ORDENADAS");
        scanf("%hd", &opcao);

        switch(opcao)
        {
            case 1:
                puts("OPCAO (1): lista l1\nOPCAO (2): lista l2\nOPCAO (3): lista l3(le)");
                scanf("%hd", &op_sec);
                puts("INSIRA O VALOR QUE DESEJA INSERIR NO INICIO:");
                scanf("%d", &temp);
                switch(op_sec)
                {
                    case 1:
                        insere_inicio(l1, temp);
                    break;
                    case 2:
                        insere_inicio(l2, temp);
                    break;
                    case 3:
                        insere_inicio(le, temp);
                    break;
                }
                break;
            case 2:
                puts("INSIRA O VALOR QUE DESEJA INSERIR 'ANTES DE' formato:(val numPosterior)");
                scanf("%d %d", &temp, &temp2);
                insere_antes(le, temp, temp2);
                break;
            case 3:
                puts("OPCAO (1): REMOVER PRIMEIRA OCORRENCIA");
                puts("OPCAO (2): REMOVER TODAS AS OCORRENCIAS");
                scanf("%hd", &op_sec);
                puts("INSIRA O VALOR QUE DESEJA REMOVER:");
                scanf("%d", &temp);
                switch(op_sec)
                {
                    case 1:
                        remove_elemento(le, temp);
                        break;
                    case 2:
                        remove_todos_elementos(le, temp);
                        break;
                }
                break;
            case 4:
                printf("l1 = ");
                imprime(l1);
                printf("l2 = ");
                imprime(l2);
                printf("l3 = ");
                imprime(le);
                break;
            case 5:
                printf("l1 = ");
                imprime_rec(l1);
                printf("l2 = ");
                imprime_rec(l2);
                printf("l3 = ");
                imprime_rec(le);
                break;
            case 6:
                puts("INSIRA O VALOR QUE DESEJA BUSCAR:");
                scanf("%d", &temp);
                temp_cell = busca(le, temp);
                printf("o valor de sua celula eh: %d\n", temp_cell->dado);
                break;
            case 7:
                puts("INSIRA O VALOR QUE DESEJA BUSCAR RECURSIVAMENTE:");
                scanf("%d", &temp);
                temp_cell = busca_rec(le, temp);
                printf("o valor de sua celula eh: %d\n", temp_cell->dado);
                break;
            case 8:
                divide_lista(le, l1, l2);
                break;
            case 9:
                mescla_listas(l1, l2, le);
                break;
        }
    }

    free(le);
    free(l1);
    free(l2);
    
    return 0;
}