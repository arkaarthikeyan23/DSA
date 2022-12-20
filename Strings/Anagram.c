//Two strings are formed using same set of characters
#include<stdio.h>

int main()
{
    char A[]="decimal";
    char B[]="medical";

    int H[26]={0}, i;
    for(int i=0; A[i]!='\0'; i++){
        H[A[i]-97]++;
    }
    for(i=0; B[i]!='\0'; i++){
        H[B[i]-97]--;
        if(H[B[i]-97]<0){
            printf("Not Anagram");
            break;
        }
    }
    if(B[i]=='\0'){
        printf("Anagram");
    }
}