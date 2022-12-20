#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size, rear, front;
    int *arr;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->rear  = -1;
    q->front = -1;
    q->arr=(int*)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q, int val)
{
    if(q->rear == q->size-1){
        printf("Queue is full");
    }
    else{
        q->rear++;
        q->arr[q->rear] = val;
    }
}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->rear == q->front){
        printf("Queue is empty");
    }
    else{
        q->front++;
        x = q->arr[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    for(int i=q.front+1; i<=q.rear; i++){
        printf("%d ",q.arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    create(&q,5);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);

    display(q);
    printf("%d\n",dequeue(&q));
    display(q);
}