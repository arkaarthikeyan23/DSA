//By using auxiliary array
#include<stdio.h>

void permute(char s[], int k)
{
    static int A[10]={0};
    static char R[10];

    if(s[k]=='\0'){
        R[k]  ='\0';
        printf("%s\n",R);
    }
    else{
        for(int i=0; s[i]!='\0'; i++)
        {
            if(A[i]==0){
                R[k] = s[i];
                A[i] = 1;
                permute(s,k+1);
                A[i] = 0;
            }
        }
    }
}

int main()
{
    char s[]="ABC";
    permute(s,0);
    return 0;
}