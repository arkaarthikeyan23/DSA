#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next=NULL;
    last = first;
    for(int i=1; i<n; i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void insert(int index, int val)
{
    struct Node *p=first, *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    if(index==0){
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else{
        for(int i=0; i<index-1; i++){
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if(p->next){
            p->next->prev = t;
        }
        p->next=t;
    }
}

void display()
{
    struct Node *p=first;
    printf("The elements in the linked list are:\n");
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}

int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);
    insert(3,5);
    display();
}
