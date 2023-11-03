/*
1 - remocao de uma folha -> pai recebe filho nulo
    1.1- remocao de um no com subarvore esquerda nula -> pai recebe filho subarvore direita
    1.2 - remocao de um no com subarvore direita nula -> pai recebe filho subarvore esquerda
2 - remocao de um no com dois filhos nao nulos -> resolve com um dos casos anteriores:
    - troca com o menor valor da subarvore direita, que por sua vez tem o filho esquerdo nulo.


*/

node * remove(no * raiz, int x)
{
    if(raiz != NULL && raiz->dado != x)
    {
        if(x < raiz->dado)
            raiz->esq = remove(raiz->esq, x);
        else
            raiz->dir = remove(raiz->dir, x);
    }

    if(raiz->dado == x)
    {
        if((raiz->esq == NULL)) return raiz->dir;// caso 1.1
        else if(raiz->dir == NULL) return raiz->esq;// caso 1.2
    }
    else
    {
        int ch;
        raiz->dir = remove_sucessor(raiz->dir, &ch);
        raiz->dado = ch;
        return raiz;
    }
    return raiz;
}

node * remove_sucessor(node * raiz, int * ch)
{
    if(raiz->esq == NULL)
    {
        *ch = raiz->dado;
        return raiz->dir;
    }
    raiz->esq = remove_sucessor(raiz->esq, ch);
    return raiz;
} 