#include "header.h"

int main()
{
    char opcao;
    celula * le = criar_lista();

    while(opcao != 0)
    {
        int temp;
        celula * temp_cell;

        puts("OPCAO (0): FECHAR O PROGRAMA\n"
             "OPCAO (1): INSERIR NA LISTA\n"
             "OPCAO (2): REMOVER DA LISTA\n"
             "OPCAO (3): IMPRIMIR LISTA\n"
             "OPCAO (4): BUSCAR NA LISTA POR ITERAÇAO\n"
             "OPCAO (5): BUSCAR NA LISTA POR RECURSAO");
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
                imprimir_lista(le);
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
        }
    }

    free(le);
}

/*FUNCTIONS DEFINITIONS*/
celula * criar_lista()
{
    celula * head = malloc(sizeof(celula));
    if(!head)
        abort();
    head->prox = NULL;
    return head;
}
void inserir_na_lista(celula * head, int elemento) //insere no final da lista
{
    celula * novo = malloc(sizeof(celula));
    celula * aux;
    if(!novo)
        abort();
    aux = head;
    novo->dado = elemento;

    while(aux->prox != NULL) aux = aux->prox;
    aux->prox = novo;
    novo->prox = NULL;
}
int remover_da_lista(celula * head, int elemento) //provavelmente vai usar busca, ficar atento
{
    celula * lixo = head->prox;
    celula * aux = head;
    //caso 1: nao haver elementos a serem removidos
    if(head->prox == NULL)
        return 1;

    while(lixo->dado != elemento && lixo->prox != NULL) 
    {
        lixo = lixo->prox;
        aux = aux->prox;
    }

    //caso 4: nao haver o elemento
    if(lixo->prox == NULL && lixo->dado != elemento)
        return 1;
    //caso 2: remover no inicio ou meio da lista
    //caso 3: remover no final da lista
    aux->prox = lixo->prox;
    lixo->prox = NULL;
    free(lixo);
    return 0; 
}
int imprimir_lista(celula * head)
{
    celula * aux = head;

    if(aux->prox == NULL) return 1; //lista vazia
    aux = aux->prox;

    puts("Lista:");
    while(aux->prox != NULL)
    {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("%d\n", aux->dado);
    return 0;
}