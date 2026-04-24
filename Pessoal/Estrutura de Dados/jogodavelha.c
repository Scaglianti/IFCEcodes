#include <stdio.h>
#include <stdlib.h>

void imprime(float*mat){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
                printf("%c",( (int)mat[i*3+j] == 0 ) ? ' ' : ( (int)mat[i*3+j] == 1 ) ? 'X' : 'O' );
        }
        printf("\n");
    }
    
}
int main(){
    float* mat= malloc(sizeof(float)*9);
    for(int i=0;i<9;i++){
        mat[i]=0;
    }
    mat[0]=1;
    mat[4]=2;
    mat[8]=1;
    imprime(mat);
    free(mat);
}