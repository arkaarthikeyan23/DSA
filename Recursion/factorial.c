#include<stdio.h>

int fact(int n)
{
    if(n==0){
        return 1;
    }
    return fact(n-1)*n;
}

int iterative(int n){
    int result=1;
    for(int i=1; i<=n; i++){
        result = result*i;
    }
    return result;
}

int main()
{
    int result1 = fact(5);
    int result2 = iterative(5);
    printf("%d\n%d",result1,result2);
    return 0;
}