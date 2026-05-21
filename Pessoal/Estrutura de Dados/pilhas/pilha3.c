#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    char letra;
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
    return (p->topo  == NULL);
}

void push(Pilha* p, char c)
{
    Lista* n = (Lista*)malloc(sizeof(Lista));
    if(n==NULL)
    {
        exit(1);
    }

    n->letra = c;
    n->prox = p->topo;
    p->topo = n;
}

char pop(Pilha* p)
{
    if(vazio(p))
    {
        printf("Sem valores para serem retirados!\n");
        return '\0';
    }
    Lista* n = p->topo;
    char c = n->letra;
    p->topo = n->prox;
    free(n);
    return c;
}

void mostrar(Pilha* p)
{
    Lista* n = p->topo;
    if(vazio(p))
    {
        printf("Sem palavras para serem mostradas!");
        return;
    }

    printf("A palavra eh ");
    while(n != NULL && n->letra != '\0')
    {
        printf("%c",n->letra);
        n = n->prox;
    }
}

void esvaziar(Pilha* p)
{
    if(vazio(p))
    {
        printf("Sem valores para serem removidos!!\n");
        return;
    }

    Lista* n = p->topo;

    while(n!=NULL)
    {
        p->topo = n->prox;
        free(n);
        n = p->topo;
    }
}

void inverter(char* palavra)
{
    Pilha p;
    cria(&p);
    int i;

    for(i = 0;palavra[i] != '\0'; i++)
    {
        push(&p, palavra[i]);
    }
    for(i=0; !vazio(&p); i++)
    {
        palavra[i] = pop(&p);
    }
    palavra[i] = '\0';
}

int main()
{
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    inverter(palavra);

    printf("Invertida: %s\n", palavra);

    return 0;
}