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

/*void Rdisplay(struct Node *p)
{
    if(p){
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
}*/

void Rdisplay(struct Node *p)
{
    if(p){
        Rdisplay(p->next);
        printf("%d ",p->data);
    }
}

int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    printf("The reverse of linked list are:\n");
    Rdisplay(first);
}
