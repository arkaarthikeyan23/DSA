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


void display()
{
    struct Node *t=first;
    printf("The elements in the linked list are:\n");
    while(t!=NULL){
        printf("%d ",t->data);
        t = t->next;
    }
}

int isSorted()
{
    int val = -65536;
    struct Node *p=first;
    while(p){
        if(p->data < val){
            return 0;
        }
        val = p->data;
        p = p->next;
    }
    return 1;
}

int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    if(isSorted()){
        printf("List is sorted in increasing order\n");
    }
    else{
        printf("List is not sorted in increasing order\n");
    }
    display();
}