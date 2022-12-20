#include <stdio.h>

void DFS(int G[7][7], int u, int n)
{
    static int visited[7]={0};
    
    if(visited[u]==0){
        printf("%d ",u);
        visited[u]=1;
        for(int v=1; v<=n; v++){
            if(G[u][v]==1 && visited[v]==0){
                DFS(G,v,n);
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
    DFS(G,1,7);
}