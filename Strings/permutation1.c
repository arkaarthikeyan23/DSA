//By using swapping
#include<stdio.h>

void swap(char *a, char *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void permute(char s[], int l, int h)
{
    if(l==h){
        printf("%s\n",s);
    }
    else{
        for(int i=l; i<=h; i++)
        {
            swap(&s[i],&s[l]);
            permute(s,l+1,h);
            swap(&s[i],&s[l]);
        }
    }
}



int main()
{
    char s[]="ABC";
    permute(s,0,2);
    return 0;
}