#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int valor;
    struct elemento* prox;
}Lista;

Lista* lista_enfileira(Lista* lista1, int valor)
{
    Lista* p;
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if(!novo) exit(1);
    novo->valor = valor;
    novo->prox = NULL;

    if(lista1 == NULL)
    {
        p = novo;
        return p;
    }

    for(p = lista1; p->prox != NULL; p = p->prox);
    p->prox = novo;

    return lista1;
}