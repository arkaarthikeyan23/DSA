//Finding multile missing element (sorted)
#include<stdio.h>

int main()
{
    int n=11;
    int arr[] = {6,7,8,9,11,12,15,16,17,18,19};
    int l=arr[0], h=arr[n-1];
    int diff=l-0;
    for(int i=0; i<n; i++){
        if(arr[i]-i != diff){
            while(diff < arr[i]-i){
                printf("Missing element:%d\n",i+diff);
                diff++;
            }
        }
    }
}