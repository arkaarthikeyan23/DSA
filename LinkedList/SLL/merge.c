#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL, *second=NULL, *third=NULL;

void create1(int A[], int n)
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

void create2(int A[], int n)
{
    struct Node *t, *last;
    second = (struct Node*)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
    for(int i=1; i<n; i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
} 

void merge(struct Node *p, struct Node *q)
{
    struct Node *last=NULL;
    if(p->data < q->data){
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else{
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p)
        last->next=p;
    else
        last->next=q;
}

void display(struct Node *p)
{
    struct Node *t=p;
    printf("The elements in the linked list are:\n");
    while(t!=NULL){
        printf("%d ",t->data);
        t = t->next;
    }
}

int main()
{
    int A[]={10,20,30,40,50};
    int B[]={5,15,25,35,45};
    create1(A,5);
    create2(B,5);
    printf("After Merging:\n");
    merge(first,second);
    display(third);
}