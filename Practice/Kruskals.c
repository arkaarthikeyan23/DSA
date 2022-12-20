#include<stdio.h>
#define I 32767

int set[8]={-1,-1,-1,-1,-1,-1,-1,-1};

void MyUnion(int u, int v)
{
    if(set[u] < set[v]){
        set[u] = set[u]+set[v];
        set[v] = u;
    }
    else{
        set[v] = set[v]+set[u];
        set[u] = v;
    }
}

int find(int u)
{
    int x=u;
    while(set[x]>0){
        x = set[x];
    }
    return x;
}
int edges[3][9] = {{1,1,2,2,3,4,4,5,5},
                   {2,6,3,7,4,5,7,6,7},
                   {25,5,12,10,8,16,14,20,18}};
int included[9]={0};
int t[2][6];

void main()
{
    int u, v, k, min=I, e=9, n=7, i=0;
    while(i<n-1){
        min=I;
        for(int j=0; j<e; j++){
            if(included[j]==0 && edges[2][j]<min){
                min=edges[2][j];
                k=j;
            }
        }
        u = edges[0][k];    v = edges[1][k];
        if(find(u)!=find(v)){
            t[0][i] = u;
            t[1][i] = v;
            MyUnion(find(u),find(v));
            i++;
        }
        included[k]=1;
    }
    for(int i=0; i<n-1; i++){
        printf("(%d->%d)\n",t[0][i],t[1][i]);
    }
}