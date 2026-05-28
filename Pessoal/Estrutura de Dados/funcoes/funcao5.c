#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float x,y;
}Ponto;

typedef struct
{
    float r;
    Ponto* centro;
}Circulo;

int circ_colide(Circulo* A, Circulo* B)
{
    float distanciax = A->centro->x - B->centro->x;
    if(distanciax < 0) distanciax * (-1);
    
    float distanciay = A->centro->y - B->centro->y;
    if(distanciay < 0) distanciay * (-1);

    float distanciatotal = distanciay + distanciax;
    float distanciar = A->r + B->r;

    float colisao = distanciatotal - distanciar;
    if(colisao <= distanciar) return 1;
    else return 0;
}