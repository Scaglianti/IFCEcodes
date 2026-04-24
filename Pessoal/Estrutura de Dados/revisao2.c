#include <stdio.h>
#include <stdlib.h>

float* mutiplica(int n,float* mat1,float* mat2){
    float* resultado= malloc(sizeof(float)*n*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            resultado[i*n+j]=0;
            for(int k=0;k<n;k++){
                resultado[i*n+j]+=mat1[i*n+k]*mat2[k*n+j];
            }
        }
    }
    return resultado;
}