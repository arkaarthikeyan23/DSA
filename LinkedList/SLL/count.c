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

/*int count()
{
    int c=0;
    struct Node *t = first;
    while(t!=NULL){
        c++;
        t = t->next;
    }
    return c;
}*/
int Rcount(struct Node *p)
{
    if(p!=NULL){
        return Rcount(p->next)+1;
    }
    else{
        return 0;
    }
}

int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    //printf("No. of. Nodes in the linked list:%d\n",count());
    printf("No. of. Nodes in the linked list:%d\n",Rcount(first));
}