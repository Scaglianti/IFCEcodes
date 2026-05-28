#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int info, prioridade;
    struct elemento* prox;
}Lista;

typedef struct fila
{
    Lista* inicio;
    Lista* fim;
}Fila;

void inicializar(Fila* f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

int vazia(Fila* f)
{
    return (f->inicio == NULL);
}

void inserir(Fila* f, int valor, int prioridade)
{
    Lista* l = (Lista*)malloc(sizeof(Lista));
    l->prioridade = prioridade;
    l->info = valor;
    l->prox = NULL;
    Lista* p = f->inicio;
    Lista* aux = p;

    if(vazia(f))
    {
        f->inicio = l;
        f->fim = l;
    }
    else
    {
        for(int prio = prioridade;p!=NULL;p=p->prox)
        {
            if(prio<p->prioridade)
            {
                
            }
            aux = p;
        }
        f->fim->prox = l;
        f->fim = l;
    }
}

void organizar(Fila* f)
{
    Lista* aux = f->inicio;
    int p = aux->prioridade;
    if(vazia(f))
    {
        return;
    }
    while()
}

int retirar(Fila* f)
{
    if(vazia(f))
    {
        printf("Lista já se encontra vazia!");
        return -1;
    }
    Lista* aux = f->inicio;
    int valor = aux->info;
    f->inicio = aux->prox;
    if(f->inicio == NULL)
    {
        f->fim = NULL;
    }
    
    free(aux);
    return valor;
}

void imprimir(Fila* f)
{
    Lista* l = f->inicio;
    if(vazia(f)){
        printf("A lista está vazia, sem valores para a amostragem");
        return;
    }

    while(l!=NULL)
    {
        printf("%d ",l->info);
        l = l->prox;
    }
    printf("/n");
}

void liberar(Fila* f)
{
    Lista* aux;

    while(f->inicio != NULL)
    {
        aux = f->inicio;
        f->inicio = aux->prox;

        free(aux);
    }
    f->fim=NULL;
}

int main()
{
    Fila* f;

    inicializar(f);

    inserir(f, 1);
    inserir(f, 2);
    inserir(f, 3);

    printf("item removido: %d/n", retirar(f));

    imprimir(f);
    liberar(f);

    return 0;
}