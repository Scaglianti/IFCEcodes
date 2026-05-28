#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int valor;
    struct elemento* prox;
}Lista;

typedef struct
{
    Lista* inicio;
    Lista* fim;
}Fila;

void cria(Fila* f)
{
    f->fim = NULL;
    f->inicio = NULL;
}

int vazio(Fila* f)
{
    return f->inicio == NULL;
}

void push(Fila* f, int valor)
{
    Lista* n = (Lista*)malloc(sizeof(Lista));
    if(!n) exit(1);

    n->valor = valor;
    n->prox = NULL;

    if(vazio(f))
    {
        f->inicio = f->fim = n;
    }
    else
    {
        f->fim->prox = n;
        f->fim = n;
    }
}

int pop(Fila* f)
{
    Lista* aux = f->inicio;
    if(vazio(f)) return -1;

    int valor = aux->valor;

    f->inicio = aux->prox;
    free(aux);

    if(f->inicio == NULL)
    {
        f->fim = NULL;
    }

    return valor;
}

void esvazia(Fila* f)
{
    Lista* p = f->inicio;
    if(vazio(f)) return;

    while(p != NULL)
    {
        f->inicio = p->prox;
        free(p);
        p = f->inicio;
    }

    free(f);
}