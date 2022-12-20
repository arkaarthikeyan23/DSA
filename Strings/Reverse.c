#include<stdio.h>

int main()
{
    char A[]="Python";
    /*
    char B[8];
    int i,j;
    for(i=0; A[i]!='\0'; i++){}
    for(i=i-1, j=0; i>=0; j++,i--){
        B[j] = A[i];
    }
    B[j]='\0';
    printf("%s",B);
    */
   //Inplace Reversing
   int i=0,j;
   for(j=0; A[j]!='\0'; j++){}
   j=j-1;
   for(; i<j; i++,j--){
        char t = A[i];
        A[i] = A[j];
        A[j] = t;
   }
   printf("%s",A);
}