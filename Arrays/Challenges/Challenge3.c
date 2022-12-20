//Finding multile missing element (sorted)
#include<stdio.h>
#include<stdlib.h>
int Min(int a[], int n)
{
    int min = a[0];
    for(int i=1; i<n; i++){
        if(a[i]<min){
            min = a[i];
        }
    }
    return min;
}

int Max(int a[], int n)
{
    int max = a[0];
    for(int i=1; i<n; i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}

int main()
{
    int n=10;
    int arr[] = {3,7,4,9,12,6,1,11,2,10};
    int min = Min(arr,n);
    int max = Max(arr,n);

    int* H = (int*)malloc(sizeof(int)*(max+1));
    for(int i=0; i<=max; i++){
        H[i]=0;
    }
    int l=min, h=max;
    for(int i=0; i<n; i++){
        H[arr[i]]++;
    }
    for(int i=l; i<=h; i++){
        if(H[i]==0){
            printf("Missing element:%d\n",i);
        }
    }
}