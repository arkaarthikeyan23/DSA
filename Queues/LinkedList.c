#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int val)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    if(temp==NULL){
        printf("Queue  is Full\n");
    }
    else{
        temp->data = val;
        temp->next = NULL;
        if(front==NULL){
            rear = front = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
    }
}

int dequeue()
{
    int x=-1;
    struct Node *temp;
    if(front==NULL){
        printf("Queue is Empty\n");
    }
    else{
        temp = front;
        front = front->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

void display()
{
    struct Node *temp=front;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();
    printf("%d\n",dequeue());
    display();
}
