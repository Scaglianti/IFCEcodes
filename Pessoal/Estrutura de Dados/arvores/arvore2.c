#include <stdio.h>
#include <stdlib.h>

typedef struct no{
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

Arv* inserir(Arv* a, int valor)
{
    if(a == NULL){
        return criar(valor);
    }

    if(valor < a->valor)
    a->esq = inserir(a->esq,valor);
    if(valor > a->valor)
    a->dir = inserir(a->dir,valor);

    return a;
}

Arv* busca(Arv* a, int valor)
{
    if(a == NULL || a->valor == valor)
    {
        return a;
    }

    if(a->valor > valor)
    return busca(a->esq, valor);
    
    return busca(a->dir, valor);
}

void imprime_pre(Arv* a)
{
    if(!a==NULL)
    {
        printf("%d ",a->valor);
        imprime(a->esq);
        imprime(a->dir);
    }
}
void imprime_sim(Arv* a)
{
    if(!a==NULL)
    {
        imprime(a->esq);
        printf("%d ",a->valor);
        imprime(a->dir);
    }
}
void imprime_pos(Arv* a)
{
    if(!a==NULL)
    {
        imprime(a->esq);
        imprime(a->dir);
        printf("%d ",a->valor);
    }
}

int altura(Arv* a)
{
    if(a == NULL)
    return -1;

    int altdir = altura(a->dir);
    int altesq = altura(a->esq);

    if(altdir > altesq)
    return altdir + 1;

    return altesq; + 1;
}

int contarnos(Arv* a)
{
    if(a == NULL)
    {
        return 0;
    }

    return 1 + contarnos(a->esq) + contarnos(a->dir);
}