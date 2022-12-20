#include<stdio.h>

int main()
{
    char A[]="finding";
    int H=0, X;
    for(int i=0; A[i]; i++){
        X=1;
        X = X<<(A[i]-97);
        if((X&H)>0){
            printf("%c is duplicate\n",A[i]);
        }
        else{
            H = X|H;
        }
    }  
}