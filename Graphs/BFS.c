#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
}*rear=NULL, *front=NULL;

void enqueue(int val)
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    if(q==NULL){
        printf("Queue is FULL\n");
    }
    else{
        q->data = val;
        q->next = NULL;
        if(front==NULL){
            rear = front = q;
        }
        else{
            rear->next = q;
            rear = q;
        }
    }
}

int dequeue()
{
    if(front==NULL){
        printf("Queue is Empty\n");
        return -1;
    }
    else{
        struct Queue *temp = front;
        int x = temp->data;
        front = front->next;
        free(temp);
        return x;
    }
}

int isEmpty()
{
    return front==NULL?1:0;
}


void BFS(int G[7][7], int start, int n)
{
    printf("%d ",start);
    int visited[7] = {0};
    visited[start] = 1;
    enqueue(start);
    while(!isEmpty()){
        int u = dequeue();
        for(int v=1; v<=n; v++){
            if(G[u][v]==1 && visited[v]==0){
                printf("%d ",v);
                visited[v]=1;
                enqueue(v);
            }
        }
    }
}

int main()
{
    int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}}; 
    BFS(G,1,7); 
    
}