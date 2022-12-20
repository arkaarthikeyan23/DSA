#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(int val)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    if(temp==NULL){
        printf("Stack is FULL\n");
    }
    else{
        temp->data = val;
        temp->next = top;
        top = temp;
    }
}

int pop()
{
    struct node *temp;
    int x=-1;
    if(top==NULL){
        printf("Stack is empty\n");
    }
    else{
        temp = top;
        top = top->next;
        x = temp->data;
    }
    return x;
}

void display()
{
    struct node *temp;
    temp = top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    
    printf("%d\n",pop());
    display();
}