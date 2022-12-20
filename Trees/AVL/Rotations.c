#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    int data, height;
    struct Node *right;
}*root=NULL;

int nodeHeight(struct Node *p)
{
    int hl = (p && p->left)? p->left->height : 0;
    int hr = (p && p->right)? p->right->height : 0;
    return hl>hr?hl+1 : hr+1;
}

int balanceFactor(struct Node *p)
{
    int hl = (p && p->left)? p->left->height : 0;
    int hr = (p && p->right)? p->right->height : 0;

    return hl-hr;
}

struct Node* LLRotation(struct Node *p)
{
    struct Node *pl = p->left;
    struct Node *plr = pl->right;

    pl->right = p;
    p->left = plr;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if(p==root)
        root = pl;
    return pl;
}

struct Node* LRRotation(struct Node *p)
{
    struct Node* pl = p->left;
    struct Node* plr = pl->right;

    pl->right = plr->right;
    pl->left = plr->right;

    plr->left = pl;
    plr->right  = p;

    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);

    if(root==p)
        root=plr;
    return plr;
}

struct Node* RRRotation(struct Node *p)
{
    int lbf,rbf;
    struct Node *pr=p->right;
    pr->height=0;
    p->right=pr->left;
    pr->left=p;
    lbf=nodeHeight(p->left)+1;
    rbf=nodeHeight(p->right)+1;
    p->height=lbf-rbf;
    if(p==root)
        root=pr;
    return pr;
}

struct Node* RLRotation(struct Node *p)
{
    int lbf,rbf;
    struct Node *pr=p->right;
    struct Node *prl=pr->left;
    prl->height=0;

    p->right=prl->left;
    pr->left=prl->right;
    prl->right=pr;
    prl->left=p;
    lbf=nodeHeight(p->left)+1;
    rbf=nodeHeight(p->right)+1;
    p->height=lbf-rbf;
}

struct Node* Rinsert(struct Node*p,int key)
{
    struct Node *t;
    if(p==NULL){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->left = t->right = NULL;
        return t;
    }

    if(key < p->data){
        p->left = Rinsert(p->left,key);
    }
    else if(key > p->data){
        p->right = Rinsert(p->right,key);
    }
    p->height = nodeHeight(p);
    //Rotations
    if(balanceFactor(p) == 2 && balanceFactor(p->left)==1){
        return LLRotation(p);
    }
    else if(balanceFactor(p) == 2 && balanceFactor(p->left)==-1){
        return LRRotation(p);
    }
    else if(balanceFactor(p) == -2 && balanceFactor(p->right)==-1){
        return RRRotation(p);
    }
    else if(balanceFactor(p) == -2 && balanceFactor(p->right)==1){
        return RLRotation(p);
    }

    return p;
}

void Inorder(struct Node *p)
{
    if(p){
        Inorder(p->left);
        printf("%d ",p->data);
        Inorder(p->right);
    }
}

int main()
{
    root = Rinsert(root,30);
    Rinsert(root,50);
    Rinsert(root,40);
    Rinsert(root,20);
    Rinsert(root,10);
    Rinsert(root,42);
    Rinsert(root,46);

    Inorder(root);
}