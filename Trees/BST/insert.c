#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *left;
    int data;
    struct Node *right;
}*root=NULL;

void insert(int key)
{
    struct Node *t=root, *p,*r;
    if(root==NULL){
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data=key;
        root->left = root->right = NULL;
        return;
    }
    while(t){
        r=t;
        if(key==t->data){
            return;
        }
        else if(key<t->data){
            t = t->left;
        }
        else{
            t = t->right;
        }
    }
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = key;
    p->left = p->right =NULL;
    if(key < r->data){
        r->left=p;
    }else{
        r->right=p;
    }
}

void Inorder(struct Node *p)
{
    if(p){
        Inorder(p->left);
        printf("%d ",p->data);
        Inorder(p->right);
    }
}

struct Node* search(int key)
{
    struct Node *t=root;
    while(t){
        if(t->data == key)
            return t;
        else if(key < t->data)
            t = t->left;
        else
            t = t->right;
    }
    return NULL;
}

struct Node* Rinsert(struct Node *p, int key)
{
    if(p==NULL){
        struct Node *t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->left = t->right = NULL;
        return t;
    }

    if(key < p->data){
        p->left = Rinsert(p->left,key);
    }
    else{
        p->right = Rinsert(p->right,key);
    }
    return p;
}

int height(struct Node *p)
{
    if(p==NULL) 
        return 0;
    int x = height(p->left);
    int y = height(p->right);
    return x>y?x+1:y+1;
}

struct Node* InPre(struct Node*p)
{
    while(p && p->right!=NULL){
        p = p->right;
    }
    return p;
}

struct Node* InSucc(struct Node*p)
{
    while(p && p->left!=NULL){
        p = p->left;
    }
    return p;
}

struct Node* delete(struct Node *p , int key)
{
    if(p==NULL)
        return NULL;
    if(p->left==NULL && p->right==NULL){
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }
    struct Node *q;
    if(key < p->data){
        p->left = delete(p->left, key);
    }
    else if(key > p->data){
        p->right = delete(p->right, key);
    }
    else{
        if(height(p->left) > height(p->right)){
            q = InPre(p->left);
            p->data = q->data;
            p->left = delete(p->left,q->data);
        }
        else{
            q = InSucc(p->right);
            p->data = q->data;
            p->right = delete(p->right,q->data);
        }
    }
    return p;
}

int main()
{
    root = Rinsert(root,50);
    Rinsert(root,10);
    Rinsert(root,40);
    Rinsert(root,20);
    Rinsert(root,30);

    delete(root,30);

    printf("Inorder Traversal:\n");
    Inorder(root);
    struct Node *temp=search(30);
    if(temp)
        printf("\n%d is found",temp->data);
    else
        printf("\n10 is not found");
}