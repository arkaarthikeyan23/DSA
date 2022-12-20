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

void sortedInsert(int val)
{
    struct Node *p=first, *q=NULL, *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;

    if(first==NULL){
        first=t;
    }
    else{
        while(p && p->data < val){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next = p;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
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
    sortedInsert(1);
    sortedInsert(8);
    display();
}