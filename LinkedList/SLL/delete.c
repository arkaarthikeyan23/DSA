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

int delete(int index)
{
    int x=-1;
    struct Node *p=first, *q=NULL;
    if(index==1){
        x = p->data;
        first = first->next;
        free(p);
        return x;
    }
    else{
        for(int i=0; i<index-1 && p; i++){
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
    }
    return x;
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
    printf("%d\n",delete(1));
    display();
}