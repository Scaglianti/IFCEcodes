#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

enum
{
    RET,
    TRI,
    CIR
};

typedef struct elemento
{
    int tipo;
    void* info;
    struct elemento* prox;
}Lista;

typedef struct
{
    float h,b;    
}Ret;

typedef struct
{
    float h,b;    
}Tri;

typedef struct
{
    float r;    
}Cir;

Lista* cria_ret(float h, float b)
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

Lista* cria_tri(float h, float b)
{
    Lista* l = (Lista*)malloc(sizeof(Lista));
    if(!l) exit(1);

    Tri* t = (Tri*)malloc(sizeof(Tri));
    if(!t) exit(1);

    t->b = b;
    t->h = h;

    l->info = t;
    l->prox = NULL;
    l->tipo = TRI;

    return l;
}

Lista* cria_cir(float r)
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

float area_ret(Ret* r)
{
    float a = r->b * r->h;
    return a;
}

float area_tri(Tri* t)
{
    float a = (t->b * t->h) / 2;
    return a;
}

float area_cir(Cir* c)
{
    float a = c->r * c->r * PI;
    return a;
}

float area(Lista* l)
{
    float a;

    switch(l->tipo)
    {
        case RET:
        a = area_ret(l->info);
        break;
        case TRI:
        a = area_tri(l->info);
        break;
        case CIR:
        a = area_cir(l->info);
        break;
    }

    return a;
}

float media_area(Lista* l, int geometria)
{
    Lista* p = l;
    float media = 0;
    int cont = 0;

    while(p!=NULL)
    {
        if(geometria == p->tipo)
        {
            media += area(p);
            cont++;
        }

        p = p->prox;
    }
    media /= cont;
    
    return media;
}

Lista* push(Lista* atual, Lista* novo)
{
    novo->prox = atual;
    return novo;
}

int main()
{
    Lista* l = cria_ret(2,5);

    l = push(l,cria_tri(7,6));
    l = push(l,cria_tri(5,3));
    l = push(l,cria_tri(7,2));
    l = push(l,cria_tri(9,8));
    l = push(l,cria_tri(3,5));
    
    l = push(l,cria_ret(5,5));
    l = push(l,cria_ret(7,5));
    l = push(l,cria_ret(7,4));
    l = push(l,cria_ret(7,2));
    
    l = push(l,cria_cir(7));
    l = push(l,cria_cir(4));
    l = push(l,cria_cir(3));
    l = push(l,cria_cir(9));



    printf("Media do Retangulo: %.2f\n", media_area(l,RET));
    printf("Media do Triangulo: %.2f\n", media_area(l,TRI));
    printf("Media do Circulo: %.2f\n", media_area(l,CIR));

    return 0;
}