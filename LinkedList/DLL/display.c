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
    display();
}
