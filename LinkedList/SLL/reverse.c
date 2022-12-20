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
//Using Auxiliary array
void reverse1(int n)
{
    int* arr = (int*)malloc(sizeof(int)*n);
    struct Node *p=first;
    int index=0;
    while(p){
        arr[index++] = p->data;
        p = p->next;
    }
    index--; p=first;
    while(p){
        p->data = arr[index--];
        p = p->next;
    }

}

//Using Sliding Pointers
void reverse2()
{
    struct Node *p=first, *q=NULL, *r=NULL;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first = q;
}

void reverse3(struct Node *q, struct Node *p)//q,curr
{
    if(p){
        reverse3(p,p->next);
        p->next = q;
    }
    else{
        first = q;
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
    int A[]={3,4,5,6,7,10,15};
    create(A,7);
    display();
    //reverse1(7);//Auxiliary Array
    //reverse2();//Sliding Pointers
    reverse3(NULL,first);//Recursive
    printf("\nAfter reversing Linked List\n");
    display();
}