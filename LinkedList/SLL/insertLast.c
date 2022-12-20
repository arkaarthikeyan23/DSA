#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void insertLast(int val)
{
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    t->next = NULL;
    struct Node *last;
    if(first==NULL){
        first = last = t;
    }
    else{
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

int main()
{
    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(25);  
    display();
}