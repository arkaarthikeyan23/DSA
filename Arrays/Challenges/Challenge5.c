#include<stdio.h>

int Max(int A[], int n)
{
    int max=A[0];
    for(int i=1; i<n; i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    return max;
}

int main()
{
    int n=10;
    int A[] = {8,3,6,4,6,5,6,8,2,7};
    //printing duplicates in unsorted array
    for(int i=0; i<n-1; i++){
        int count=1;
        if(A[i]!=-1){
            for(int j=i+1; j<n; j++){
                if(A[i]==A[j]){
                    count++;
                    A[j]=-1;
                }
            }
            if(count>1){
                printf("%d appearing %d times\n",A[i],count);
            }
        }
    }


    //Hashing
    int max=Max(A,n);
    int H[max+1];
    for(int i=0; i<=max; i++){
        H[i]=0;
    }
    for(int i=0; i<n; i++){
        H[A[i]]++;
    }
    for(int i=0; i<=max; i++){
        if(H[i]>1){
            printf("\n%d appearing %d times",i,H[i]);
        }
    }
}