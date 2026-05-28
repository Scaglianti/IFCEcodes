#include <stdio.h>
#include <stdlib.h>

typedef struct ponto
{
    float x,y;
}Ponto;

Ponto* pto_cria(float x, float y)
{
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));

    p->x = x;
    p->y = y;

    return p;
}

int main()
{
    Ponto* p = pto_cria(2.5,8.4);

    printf("O ponto x: %.2f\n", p->x);
    printf("O ponto y: %.2f", p->y);

    return 0;
}