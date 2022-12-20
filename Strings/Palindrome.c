#include<stdio.h>

int main()
{
    char A[]="madam";
    int i,j;
    for(j=0; A[j]!='\0'; j++){}
    for(i=0,j=j-1; i<j; i++,j--){
        if(A[i]!=A[j]){
            printf("Not Palindrome");
            return 0;
        }
    }
    printf("Palindrome");
}