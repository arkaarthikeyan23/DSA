#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i=1; i<n; i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int Max()
{
    int max = INT_MIN;
    struct Node *t=first;
    while(t){
        if(t->data > max)
            max = t->data;
        t = t->next;
    }
    return max;
}

int Rmax(struct Node *t)
{
    if(t==NULL)
        return INT_MIN;
    int x = Rmax(t->next);
    return x > t->data? x : t->data;
}

int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    printf("Max element in the linked list:%d\n",Max());
    printf("Max element in the linked list:%d\n",Rmax(first));
}