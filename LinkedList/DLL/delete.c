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

int delete(int index)
{
    int x=-1;
    struct Node *p = first;
    if(index==1){
        first = first->next;
        if(first)
            first->prev=NULL;
        x=p->data;
        free(p);
        return x;
    }
    else{
        for(int i=0; i<index-1; i++){
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }

    return x;
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
    printf("The deleted element is : %d\n",delete(3));
    display();
}
