#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *q;
    p =(int*)malloc(5*sizeof(int));
    p[0]=1; p[1]=2; p[2]=3; p[3]=4; p[4]=5;

    q=(int*)malloc(10*sizeof(int));

    for(int i=0; i<5; i++){
        q[i]=p[i];
    }
    free(p);
    p=q;
    q=NULL;
    for(int i=0; i<5; i++){
        printf("%d ",p[i]);
    }
    p[5]=6; p[6]=7; p[7]=8; p[8]=9; p[9]=10;
    printf("\n");
    for(int i=0; i<10; i++){
        printf("%d ",p[i]);
    }
}