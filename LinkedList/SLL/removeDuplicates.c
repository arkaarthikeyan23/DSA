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

void removeDuplicates()
{
    struct Node *p=first, *q=first->next;
    while(q){
        if(p->data != q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next = q->next;
            free(q);
            q=p->next;
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
    int A[]={3,3,4,5,5,5,7};
    create(A,7);
    removeDuplicates();
    display();
}