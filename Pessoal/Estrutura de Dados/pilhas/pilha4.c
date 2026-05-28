#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int valor;
    struct lista* prox;
}Lista;

typedef struct
{
    Lista* topo;
}Pilha;

void cria(Pilha* p)
{
    p->topo = NULL;
}

int vazio(Pilha* p)
{
    return p->topo ==  NULL;
}

void push(Pilha* p, int valor)
{
    Lista* l = (Lista*)malloc(sizeof(Lista));
    if(!l) exit(1);

    l->valor = valor;
    l->prox = p->topo;

    p->topo = l;
}

int pop(Pilha* p)
{
    Lista* aux = p->topo;
    if(vazio(p)) return -1;
    
    int valor = aux->valor;
    p->topo = aux->prox;
    free(aux);

    return valor;
}

void esvazia(Pilha* p)
{
    Lista* l = p->topo;
    if(vazio(p)) return;

    while(l!=NULL)
    {
        p->topo = l->prox;
        free(l);
        l = p->topo;
    }
}