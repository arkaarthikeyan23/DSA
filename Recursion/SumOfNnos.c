#include<stdio.h>

int sum(int n)
{
    if(n==0){
        return 0;
    }
    return sum(n-1)+n;
}

int iterativeSum(int n){
    int s=0;
    for(int i=1; i<=n; i++){
        s = s+i;
    }
    return s;
}

int main()
{
    int result1 = sum(5);
    int result2 = iterativeSum(5);
    printf("%d\n%d",result1,result2);
    return 0;
}