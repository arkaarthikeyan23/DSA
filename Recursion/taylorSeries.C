#include<stdio.h>

double e(int x, int n)
{
    static double p=1, f=1, result;
    if(n==0)
        return 1;
    result = e(x,n-1);
    p = p*x;
    f = f*n;
    return result+p/f;
}

//Horner's Rule
//Recusive
/*double e1(int x, int n)
{
    static double result;
    if(n==0)
        return result;
    
    result = 1+result*x/n;
    return e1(x,n-1);    
}*/

//Iterative
double e1(int x, int n)
{
    double result=1, numerator=1, denominator=1;
    for(int i=1; i<=n; i++){
        numerator *= x;
        denominator *= i;
        result += numerator/denominator;
    }
    return result;
}

int main()
{
    // double result = e(1,10);
    // printf("%lf",result);
    printf("%lf",e1(1,10));
    return 0;
}