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

void insert(int index, int val)
{
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    t->next = NULL;
    if(index==0){
        t->next = first;
        first = t;
    }
    else if(index>0){
        struct Node *p = first;
        for(int i=0; i<index-1 && p; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}



void display()
{
    struct Node *t=first;
    printf("The elements in the linked list are:\n");
    while(t!=NULL){
        printf("%d ",t->data);
        t = t->next;
    }
}

int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    insert(0,11);
    insert(5,50);
    display();
}