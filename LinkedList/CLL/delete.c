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



void display()
{
    struct Node *p=head;
    printf("The elements in the linked list are:\n");
    do{
        printf("%d ",p->data);
        p = p->next;
    }while(p!=head);
}

int delete(int index)
{
    struct Node *p=head, *q;
    int x=-1;
    if(index==1){
        while(p->next != head){
            p = p->next;
        }
        x=head->data;
        if(p==head){
            free(head);
            head=NULL;
        }
        else{
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else{
        for(int i=0; i<index-2; i++){
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[] = {2,3,4,5,6};
    create(A,5);
    printf("The deleted element is : %d\n",delete(5));
    display();
}