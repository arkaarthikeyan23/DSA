#include<stdio.h>

//Iterative
int fib(int n)
{
    int t0=0, t1=1, sum;
    if(n<=1) 
        return n;
    for(int i=2; i<=n; i++){
        sum = t0 + t1;
        t0 = t1;
        t1 = sum;
    }
    return sum;
}

//Recursive
int fib1(int n)
{
    if(n<=1)
        return n;
    return fib1(n-2)+fib1(n-1);
}

//Memoized-->reduces excessive recursion.
int F[10];
int fib2(int n)
{
    if(n<=0){
        F[n] = n;
        return F[n];
    }
    if(F[n-2]==-1){
        F[n-2] = fib2(n-2);
    }
    if(F[n-1]==-1){
        F[n-1] = fib(n-1);
    }
    return F[n-2]+F[n-1];
}

int main()
{
    for(int i=0; i<10; i++){
        F[i] = -1;
    }
    printf("%d",fib2(10));
    return 0;
}