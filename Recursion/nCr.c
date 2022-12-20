#include<stdio.h>

int fact(int n)
{
    if(n==0)
        return 1;
    return fact(n-1)*n;
}

//Recursive
int nCr(int n, int r)
{
    int numerator, denominator;
    numerator = fact(n);
    denominator = fact(r) * fact(n-r);
    return numerator/denominator;
}

//Pascal's Triangle--> perform addition recursively
int NCR(int n, int r)
{
    if(r==0 || r==n){
        return 1;
    }
    return NCR(n-1,r-1)+NCR(n-1,r);
}

int main()
{
    printf("%d",NCR(5,1));
    return 0;
}