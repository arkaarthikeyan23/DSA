//Finding single missing element (sorted)
#include<stdio.h>

int sum(int a[], int n)
{
    int total=0;
    for(int i=0; i<n; i++){
        total += a[i];
    }
    return total;
}

int main()
{
    int arr[] = {1,2,3,4,5,7};
    int n=7;
    /*Method 1:
    int sumOfNnos = n*(n+1)/2;
    int total = sum(arr,6);
    printf("Missing Element:%d ",sumOfNnos-total);
    */
   int diff = arr[0]-0;
   for(int i=0; i<n ;i++){
        if(arr[i]-i != diff){
            printf("Missing element:%d",i+diff);
            break;
        }
   }
   return 0;
}