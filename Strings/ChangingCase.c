#include<stdio.h>

int main()
{
    char s[] = "WELCOME";
    char T[] = "WelCoMe";
    for(int i=0;s[i]!='\0'; i++)
    {
        s[i] = s[i]+32;
    }
    printf("Lower Case is %s\n",s);
    //Toggle Case:
    for(int i=0; T[i]!='\0'; i++)
    {
        if(T[i]>=65 && T[i]<=90){
            T[i] = T[i]+32;
        }
        else if(T[i]>=97 && T[i]<=122){
            T[i] = T[i]-32;
        }
    }
    printf("Toggle Case is %s",T);
}