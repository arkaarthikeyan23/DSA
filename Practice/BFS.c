#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*rear=NULL, *front=NULL;

void enqueue(int val)
{
    struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL){
        printf("Queue is Full\n");
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
    if(front==NULL){
        printf("Queue is Empty\n");
    }
    else{
        struct Node *temp = front;
        front = front->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

int isEmpty()
{
    return front==NULL?1:0;
}

void BFS(int G[7][7], int start, int n)
{
    printf("%d ",start);
    int visited[7]={0};
    visited[start]=1;
    enqueue(start);
    while(!isEmpty()){
        int u = dequeue();
        for(int v=1; v<=n; v++){
            if(visited[v]==0 && G[u][v]==1){
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