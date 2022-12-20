#include<stdio.h>

int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }
    int prev=0;
    printf("%d ",arr[prev]);
    for(int curr=1; curr<N; curr++){
        if(arr[prev]%2!=arr[curr]%2){
            printf("%d ",arr[curr]);
        }
        prev = curr;
    }
}