#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    char info[20];
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

void push(Pilha* p, char* nome)
{
    Lista* n = (Lista*)malloc(sizeof(Lista));
    if(n==NULL)
    {
        exit(1);
    }
    strcpy(n->info,nome);
    n->prox = p->topo;
    p->topo = n;
}

char* pop(Pilha* p)
{
    if(vazio(p))
    {
        printf("Sem valores para retirar!\n");
        return "";
    }
    Lista* n = p->topo;
    char* nome = (char*)malloc(sizeof(n->info));
    strcpy(nome,n->info);
    p->topo = n->prox;
    free(n);
    return nome;
}
char* top(Pilha* p)
{
    if(vazio(p))
    {
        printf("Sem valores para serem mostrados!\n");
        return "";
    }
    return p->topo->info;
}

void mostrar(Pilha* p)
{
    Lista* n = p->topo;
    int cont = 1;
    while(n!=NULL)
    {
        printf("O %d nome eh %s\n", cont, n->info);
        cont++;
        n=n->prox;
    }
}

int main()
{
    Pilha p;
    cria(&p);

    push(&p,"Pedro");
    push(&p,"Mirele");
    push(&p,"Monique");

    printf("O ultimo nome da pilha eh %s\n", top(&p));
    pop(&p);
    mostrar(&p);
}