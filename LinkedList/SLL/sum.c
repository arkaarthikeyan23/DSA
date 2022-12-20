#include<stdio.h>
#include<stdlib.h>

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

int Add()
{
    int sum=0;
    struct Node *t = first;
    while(t!=NULL){
        sum += t->data;
        t = t->next;
    }
    return sum;
}

int RAdd(struct Node *p)
{
    if(p!=NULL){
        return RAdd(p->next) + p->data;
    }
    else{
        return 0;
    }
}

int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    printf("Sum of Nodes in the linked list:%d\n",Add());
    printf("Sum of Nodes in the linked list:%d\n",RAdd(first));
}