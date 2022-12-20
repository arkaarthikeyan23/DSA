#include<stdio.h>

int fun(int n)
{
    static int x=0;
    if(n>0){
        x++;
        return fun(n-1)+x;
    }
}

void main()
{
    int x=5;
    printf("%d\n",fun(x));
}