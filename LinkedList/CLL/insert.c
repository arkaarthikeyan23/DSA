#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;
    for(int i=1; i<n; i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = head;
        last->next = t;
        last = t;
    }
}

void insert(int index, int val)
{
    struct Node *t ,*p;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    if(index==0){
        if(head==NULL){
            head=t;
            head->next=head;
        }else{
            p=head;
            while(p->next!=head)  
                p = p->next;
            p->next = t;
            t->next=head;
            head=t;
        }
    }
    else{
        p=head;
        for(int i=0; i<index-1; i++)
            p = p->next;
        t->next = p->next;
        p->next =t;
    }
}

void display()
{
    struct Node *p=head;
    printf("The elements in the linked list are:\n");
    do{
        printf("%d ",p->data);
        p = p->next;
    }while(p!=head);
}


int main()
{
    int A[] = {2,3,4,5,6};
    create(A,5);
    insert(5,10);
    display();
}