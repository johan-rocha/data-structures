#include <stdio>

// método1: vetor auxililar

typedef struct
{
    int * v;
    int n, tam;
}FP;

void heapsort(int * v, int n) // terminar ou copiar depois
{
    FP * fp = cria_heap()
}

// método2: direto no vetor

void desce_no_heap(FP * fp, int i)
{
    int esq = 2*i+1, dir = esq+1, maior_filho;
    if(esq< fp->n)
    {
        maior_filho = esq;
        if(dir < fp->n && fp->v[dir] > fp->v[esq])
            maior_filho = dir;
        
        if(fp->v[i] < fp->v[maior_filho])
        {
            exch(fp->v, i, maior_filho);
            desce_no_heap(fp, maior_filho);
        }
    }
}

void heapsort_vector(int * v, int n) //o(n log(n))
{
    for(int i=n-1, i>=0, i--)
        desce_no_heap(v, n, i);

    while(n>0)
    {
        remove(v, n); //troca a raizz com v[n-1] e aplica desce_no_heap na raiz v[0]
        n--;

    }
}

sudo dpkg --add-architecture armhf
sudo apt-get update
sudo apt-get install libc6:armhf
sudo ln -s /lib/ld-linux-armhf.so.3 /lib/ld-linux.so.3
sudo apt-get install libstdc++6:armhf
sudo wget https://www.vpn.net/installers/logmein-hamachi_2.1.0.203-1_armhf.deb
sudo dpkg -i logmein-hamachi_2.1.0.203-1_armhf.deb
sudo hamachi login