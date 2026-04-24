#include <stdio.h>
#include <stdlib.h>

float* ler(int n,int m,float *vet)
{
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%f",&vet[i*m+j]);
        }
    }
    return vet;
}
float* criar(int n, int m, float *vet)
{
    float *mat = malloc(n*m*sizeof(float));
    return mat;
}
float *soma(int n,int m,float *mat1,float *mat2)
{
    float *matsoma= criar(n,m,matsoma);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            matsoma[i*m+j]=mat1[i*m+j]+mat2[i*m+j];
        }
    }
    return matsoma;
}
float *transposta(int n,int m, float *mat)
{
    float *mattran= criar(m,n,mattran);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            mattran[j*n+i]=mat[i*m+j];
        }
    }
    return mattran;
}
float *mutiplica(int n,int m, float*mat1,float *mat2)
{
    float* matmutiplica= criar(n,m,matmutiplica);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            matmutiplica[i*m+j]=mat1[i*m+j]*mat2[i*m+j];

        }
    }
    return matmutiplica;
}
void imprimir(int n,int m,float *vet)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%.2f ",vet[i*m+j]);
        }
        printf("\n");
    }
}
int main()
{
    int n,m;
    printf("Digite o numero de linhas e colunas da matriz: ");
    scanf("%d %d",&n,&m);
    float *mat1,*mat2,*somada,*transpostada1,*transpostada2,*mutiplicada;
    printf("Digite os elementos da primeira matriz:\n");
    mat1=criar(n,m,mat1);
    ler(n,m,mat1);
    printf("Digite os elementos da segunda matriz:\n");
    mat2 = criar(n,m,mat2);
    ler(n,m,mat2);
    somada = soma(n,m,mat1,mat2);
    mutiplicada=mutiplica(n,m,mat1,mat2);
    transpostada1=transposta(n,m,mat1);
    transpostada2=transposta(n,m,mat2);
    printf("---Soma das matrizes:---\n");
    imprimir(n,m,somada);
    printf("---Mutiplicação das matrizes:---\n");
    imprimir(n,m,mutiplicada);
    printf("---Transposta da primeira matriz:---\n");
    imprimir(m,n,transpostada1);
    printf("---Transposta da segunda matriz:---\n");
    imprimir(m,n,transpostada2);
    free(mat1);
    free(mat2);
    free(somada);
    free(transpostada1);
    free(transpostada2);
    free(mutiplicada);
    return 0;
}
        