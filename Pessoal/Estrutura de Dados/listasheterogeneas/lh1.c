#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

enum
{
    RET,
    TRI,
    CIR
};
const char* geo[] = 
{
    "retangulo",
    "triangulo",
    "circulo"
};
typedef struct elemento
{
    int tipo;
    void* info;
    struct elemento* prox;
}Lista;

typedef struct
{
    float b,h;
}Ret;

typedef struct
{
    float b,h;
}Tri;

typedef struct
{
    float r;
}Cir;

Lista* cria_Ret(float b, float h)
{
    Lista* l = (Lista*)malloc(sizeof(Lista));
    if(!l) exit(1);

    Ret* r = (Ret*)malloc(sizeof(Ret));
    if(!r) exit(1);

    r->b = b;
    r->h = h;
    
    l->info = r;
    l->prox = NULL;
    l->tipo = RET;

    return l;
}

Lista* cria_Tri(float b, float h)
{
    Lista* l = (Lista*)malloc(sizeof(Lista));
    if(!l) exit(1);

    Tri* t = (Tri*)malloc(sizeof(Tri));
    if(!t) exit(1);

    t->b = b;
    t->h = h;

    l->info = t;
    l->tipo = TRI;
    l->prox = NULL;

    return l;
}

Lista* cria_Cir(float r)
{
    Lista* l = (Lista*)malloc(sizeof(Lista));
    if(!l) exit(1);

    Cir* c = (Cir*)malloc(sizeof(Cir));
    if(!c) exit(1);

    c->r = r;

    l->info = c;
    l->prox = NULL;
    l->tipo = CIR;

    return l;
}

float aRet(Ret* r)
{
    return r->b * r->h;
}

float aTri(Tri* t)
{
    return (t->b * t->h) / 2;
}

float aCir(Cir* c)
{
    return c->r * c->r * PI;
}

float area(Lista* l)
{
    float a;

    switch(l->tipo)
    {
        case CIR:
        a = aCir(l->info);
        break;
        case RET:
        a = aRet(l->info);
        break;
        case TRI:
        a = aTri(l->info);
        break;
    }
    return a;
}

float maxarea(Lista* l)
{
    Lista* p = l;
    float amax = 0;
    float aux;

    while(p!=NULL)
    {
        aux = area(p);

        if(aux > amax)
        {
            amax = aux;
        }
        p = p->prox;
    }

    return amax;
}

Lista* push(Lista* atual, Lista* novo)
{
    novo->prox = atual;
    return novo;
}

void imprimir(Lista* l)
{
    Lista* p = l;

    while(p!=NULL)
    {
        printf("O valor da media desse %s eh: %.2f\n", geo[p->tipo], area(p));
        p = p->prox;
    }
}

int main()
{
    Lista* teste = cria_Cir(4);
    
    teste = push(teste, cria_Ret(3,5));
    teste = push(teste, cria_Ret(7,2));
    teste = push(teste, cria_Tri(3,6));
    teste = push(teste, cria_Tri(3,5));

    imprimir(teste);
}