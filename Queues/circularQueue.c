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
    q->rear  = 0;
    q->front = 0;
    q->arr=(int*)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q, int val)
{
    if((q->rear+1) % q->size == q->front){
        printf("Queue is full\n");
    }
    else{
        q->rear = (q->rear+1) % q->size;
        q->arr[q->rear] = val;
    }
}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->rear == q->front){
        printf("Queue is empty\n");
    }
    else{
        q->front = (q->front+1) % q->size;
        x = q->arr[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    int i=q.front+1;
    do{
        printf("%d ",q.arr[i]);
        i = (i+1) % q.size;
    }while(i!=((q.rear+1)%q.size));
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
    enqueue(&q,50);
    enqueue(&q,60);
    display(q);
    printf("%d\n",dequeue(&q));
    display(q);
}