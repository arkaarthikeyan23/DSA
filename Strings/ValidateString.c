#include<stdio.h>

int validate(char s[])
{
    for(int i=0; s[i]!='\0'; i++){
        if(!(s[i]>=97 && s[i]<=122) && !(s[i]>=65 && s[i]<=90) && !(s[i]>=48 && s[i]<=57)){
                return 0;
        }
    }
    return 1;
}

int main()
{
    char *name = "Ani@321";
    if(validate(name)){
        printf("Valid");
    }
    else{
        printf("Invalid");
    }
}