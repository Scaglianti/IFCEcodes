#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    int info;
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
    return (p->topo == NULL);
}

void push(Pilha* p, int valor)
{
    Lista* n = (Lista*)malloc(sizeof(Lista));
    if(n==NULL)
    {
        exit(1);
    }
    n->info = valor;
    n->prox = p->topo;
    p->topo = n;
}

int pop(Pilha* p)
{
    if(vazio(p))
    {
        printf("Sem elementos para tirar!");
        return -1;
    }

    Lista* aux = p->topo;
    int valor = aux->info;
    p->topo = aux->prox;
    free(aux);

    return valor;
}

int top(Pilha* p)
{
    if(vazio(p))
    {
        printf("nada para ser mostrado");
        return -1;
    }

    return p->topo->info;
}

void mostrar(Pilha* p)
{
    Lista* n = p->topo;

    if(vazio(p))
    {
        printf("Sem valores para serem mostrados!");
        return;
    }
    
    int cont=1;
    while(n != NULL)
    {
        printf("O valor da %d informacao eh %d\n", cont,n->info);
        cont++;
        n = n->prox;
    }
}

int tamanho(Pilha* p)
{
    Lista* n = p->topo;
    int cont = 0;

    if(vazio(p))
    {
        return 0;
    }

    while(n!=NULL)
    {
        cont++;
        n = n->prox;
    }
    return cont;
}

void esvaziar(Pilha* p)
{
    if(vazio(p))
    {
        printf("A pilha ja se encontra vazia");
        return;
    }

    int tam = tamanho(p);
    while(tam>0)
    {
        pop(p);
        tam--;
    }
}
int main()
{
    Pilha n;
    cria(&n);

    push(&n,10);
    push(&n,20);
    push(&n,30);

    int valor = pop(&n);
    printf("Valor retirado: %d\n", valor);
    mostrar(&n);
    int tam = tamanho(&n);
    printf("O tamanho da pilha eh %d\n",tam);
    esvaziar(&n);
    mostrar(&n);
    return 0;
}