#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no* esq;
    struct no* dir;
}Arv;

Arv* criar(int valor)
{
    Arv* a = (Arv*)malloc(sizeof(Arv));

    a->dir = NULL;
    a->esq = NULL;
    a->valor = valor;

    return a;
}

Arv* inserir(Arv* raiz, int valor)
{
    if(raiz == NULL)
    {
        return criar(valor);
    }

    if(valor > raiz->valor)
    {
        raiz->dir = inserir(raiz->dir,valor);
    }
    else if(valor > raiz->valor)
    {
        raiz->esq = inserir(raiz->esq,valor);
    }

    return raiz;
}

Arv* vazia(void)
{
    return NULL;
}

int verifica(Arv* a)
{
    return a == NULL;
}

void imprime(Arv* a)
{
    if(!verifica(a))
    {
        
        imprime(a->esq);
        imprime(a->dir);
        printf("%d ", a->valor);
    }
}

Arv* libera(Arv* a)
{
    if(!verifica(a))
    {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
    return NULL;
}

Arv* cria_arv(int valor, Arv* esq, Arv* dir)
{
    Arv* a = (Arv*)malloc(sizeof(Arv));

    a->valor = valor;

    a->dir = dir;
    a->esq = esq;

    return a;
}
int main()
{
    Arv* a = cria_arv(3, 
        cria_arv(0, cria_arv(1,vazia(),vazia()),
        cria_arv(9,vazia(),vazia())),
    cria_arv(37,cria_arv(45,vazia(),
        cria_arv(7,vazia(),vazia())),vazia()));

    imprime(a);


    return 0;
}