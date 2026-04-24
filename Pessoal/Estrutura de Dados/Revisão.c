#include <stdio.h>
#include <stdlib.h>

float* cria(int n,int m, float *mat1){
    float* criada= malloc(sizeof(float)*n*m);
    return criada;
}
float* ler(int n,int m,float* mat1){
    int k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            k=i*m+j;
            printf("Elemento [%d][%d]: ",i,j);
            scanf("%f",&mat1[k]);
        }
    }
    return mat1;
}
void imprime(int n,int m,float* mat1){
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            k=i*m+j;
            printf("%.2f ",mat1[k]);
        }
        printf("\n");
    }
}

int main()
{
    int linha, coluna;
    linha =coluna=3;
    float* mat1 = cria(linha, coluna, mat1);
    mat1 = ler(linha, coluna, mat1);
    imprime(linha, coluna, mat1);
    return 0;
}
