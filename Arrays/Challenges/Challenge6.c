//Find Pair with a+b=K;
#include<stdio.h>

int Max(int a[], int n)
{
    int max=a[0];
    for(int i=1; i<n; i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}

int main()
{
    int n=10;
    int A[]={6,3,8,10,16,7,5,2,9,14};
    int k=10;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(A[i]+A[j]==k){
                printf("%d + %d = %d\n",A[i],A[j],k);
            }
        }
    }
    //Hashing
    int max = Max(A,n);
    int H[max+1];
    for(int i=0; i<n; i++){
        H[A[i]]=0;
    }
    for(int i=0; i<n; i++){
        if(H[k-A[i]]!=0){
            printf("%d + %d = %d\n",A[i],k-A[i],k);
        }
        H[A[i]]++;
    }


   //Sorted Array
    int b=10, l=10;
    int B[]={1,3,4,5,6,8,9,10,12,14};
    int i=0, j=b-1;
    while(i<j){
        if(B[i]+B[j]==l){
            printf("%d + %d = %d\n",B[i],B[j],l);
            i++;
            j--;
        }
        else if(B[i]+B[j]<l){
            i++;
        }
        else{
            j--;
        }
    }
}