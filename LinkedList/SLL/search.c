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

struct Node* Lsearch(struct Node*p, int key)
{
    while(p!=NULL){
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node* R_L_search(struct Node *p, int key)
{
    if(p==NULL)
        return NULL;
    if(p->data == key)
        return p;
    return R_L_search(p->next,key);
}

struct Node* Imp_L_search(struct Node *p, int key)
{
    struct Node* q=NULL;
    while(p!=NULL){
        if(p->data == key){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }
}

void display()
{
    struct Node *t=first;
    printf("The elements in the linked list are:\n");
    while(t!=NULL){
        printf("%d ",t->data);
        t = t->next;
    }
}

int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    /*struct Node *temp = Lsearch(first,10);
    if(temp){
        printf("Key is Found:%d\n",temp->data);
    }else{
        printf("Key is not Found\n");
    }
    struct Node *temp = R_L_search(first,10);
    if(temp){
        printf("Key is Found:%d\n",temp->data);
    }else{
        printf("Key is not Found\n");
    }*/
    struct Node *temp = Imp_L_search(first,15);
    temp = Imp_L_search(first,10);
    if(temp){
        printf("Key is Found:%d\n",temp->data);
    }else{
        printf("Key is not Found\n");
    }
    display();
}