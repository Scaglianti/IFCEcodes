#include <stdio.h>

void soma(int *a,int *b,int d,int e)
{
    *a=d*e;
    *b=d+e;
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    soma(&x,&y,x,y);
    printf("%d %d", x, y);

    return 0;
}