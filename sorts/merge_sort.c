#include <stdio.h>

void merge(int *v, int l, int m, int r)
{
    //quanto espaÃ§o?
    int tam = r+1-l;

    //alocar espaÃ§o auxiliar
    int *aux = malloc(tam*sizeof(int));

    //auxiliares
    int i=l; //inicio do sub-vetor esquerdo
    int j=m+1; //inicio do sub-vetor direito
    int k=0; //inicio do vetor auxiliar

    //ordenar em aux[k]
    while(k<tam) //condiÃ§Ã£o de parada do aux
    {
        if(i>m) //ordenou todo o primeiro sub-vetor
            aux[k++] = v[j++];//consome o segundo sub-vetor -> ordene no aux

        else if (j>r) //ordenou todo o segundo sub-vetor
            aux[k++] = v[i++];//consome o primeiro sub-vetor -> ordene no aux

        else if (v[i] < v[j]) //testar sub-vetores
            aux[k++] = v[i++];//ordene no aux
        else
            aux[k++] = v[j++];//ordene no aux
    }

    k=0; //indice do aux
    for(i=l; i<=r; i++) //indice do v
        v[i] = aux[k++];//copiar o aux[k] para v[i]
        
    //liberar memÃ³ria
    free(aux);
   
}

void merge_sort(int *v, int l, int r)
{
    if (l >= r) return;
    int m = (r+l)/2;
    //printf("merge_sort(v, %d, %d)\n", l, m);
    //printf("merge_sort(v, %d, %d)\n", m+1, r);
    //printf("merge(v, %d, %d, %d)\n", l, m, r);
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge1(v, l, m, r);
}