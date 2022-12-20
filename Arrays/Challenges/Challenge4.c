#include<stdio.h>

int main()
{
    int n=10;
    int A[] = {3,6,8,8,10,12,15,15,15,20};
    int lastDuplicate=0;
    //printing duplicates in sorted array
    for(int i=0; i<n-1; i++){
        if(A[i]==A[i+1] && A[i]!=lastDuplicate){
            printf("%d ",A[i]);
            lastDuplicate = A[i];
        }
    }
    //counting dulplicate
    for(int i=0; i<n-1; i++){
        if(A[i]==A[i+1]){
            int j=i+1;
            while(A[i]==A[j]) j++;
            printf("\n%d appearing %d times",A[i],j-i);
            i=j-1;
        }
    }
    //Hashing
    int max=A[n-1];
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