#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *left;
    int data;
    struct Node *right;
}*root=NULL;

struct stack
{
    int size;
    int top;
    struct Node **arr;
};

struct Queue
{
    int size, rear, front;
    struct Node **arr;
};

void createStack(struct stack *st, int n)
{
    st->top = -1;
    st->arr =(struct Node **)malloc(sizeof(struct Node *)*n);
}

void create(struct Queue *q, int size)
{
    q->size = size;
    q->rear  = 0;
    q->front = 0;
    q->arr=(struct Node**)malloc(q->size*sizeof(struct Node*));
}

void push(struct stack *st, struct Node *val)
{
    if(st->top == st->size-1){
        printf("Stack OverFlow\n");
    }
    else{
        st->top++;
        st->arr[st->top] = val;
    }
}


void enqueue(struct Queue *q, struct Node* val)
{
    if((q->rear+1) % q->size == q->front){
        printf("Queue is full\n");
    }
    else{
        q->rear = (q->rear+1) % q->size;
        q->arr[q->rear] = val;
    }
}

struct Node * pop(struct stack *st)
{
    struct Node *x=NULL;
    if(st->top == -1){
        printf("Stack UnderFlow\n");
    }
    else{
        x = st->arr[st->top--];
    }
    return x;
}

struct Node* dequeue(struct Queue *q)
{
    struct Node* x=NULL;
    if(q->rear == q->front){
        printf("Queue is empty\n");
    }
    else{
        q->front = (q->front+1) % q->size;
        x = q->arr[q->front];
    }
    return x;
}

struct Node * stackTop(struct stack st)
{
    if(!(st.top==-1)){
        return st.arr[st.top];
    }
    return NULL;
}

int isEmpty(struct Queue q){
    return q.rear == q.front;
}

void TreeCreate()
{
    struct Node *p, *t;
    struct Queue q;
    create(&q,100);
    int x;
    printf("Enter the root value\n");
    scanf("%d",&x);
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->left = root->right = NULL;
    enqueue(&q,root);
    while(!isEmpty(q)){
        p = dequeue(&q);
        printf("Enter the left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            enqueue(&q,t);
        }
        printf("Enter the right child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            enqueue(&q,t);
        }
    }
}

void preorder(struct Node *p)
{
    if(p){
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(struct Node *p)
{
    if(p){
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}

void postorder(struct Node *p)
{
    if(p){
        
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
}

void Ipreorder(struct Node *p)
{
    struct stack st;
    createStack(&st,100);
    while(p || !(st.top==-1)){
        if(p){
            printf("%d ",p->data);
            push(&st,p);
            p = p->left;
        }
        else{
            p = pop(&st);
            p = p->right;
        }
    }
}

void Iinorder(struct Node *p)
{
    struct stack st;
    createStack(&st,100);
    while(p || !(st.top==-1)){
        if(p){
            push(&st,p);
            p = p->left;
        }
        else{
            p = pop(&st);
            printf("%d ",p->data);
            p = p->right;
        }
    }
}

void levelorder(struct Node *p)
{
    struct Queue q;
    create(&q,100);
    printf("%d ",p->data);
    enqueue(&q,p);
    while(!isEmpty(q)){
        p = dequeue(&q);
        if(p->left){
            printf("%d ",p->left->data);
            enqueue(&q,p->left);
        }
        if(p->right){
            printf("%d ",p->right->data);
            enqueue(&q,p->right);
        }
    }
}

int count(struct Node *root)
{
    if(root){
        return count(root->left) + count(root->right) + 1;
    }
    return 0;
}

int height(struct Node *root){
    int x=0,y=0;
    if(root==0){
        return 0;
    }
    x = height(root->left);
    y = height(root->right);
    if(x>y)
        return x+1;
    else
        return y+1;
}

int main()
{
    TreeCreate();
    /*printf("Preorder Traversal:\n");
    preorder(root);
    printf("\nInorder Traversal:\n");
    inorder(root);
    printf("\nPostorder Traversal:\n");
    postorder(root);
    printf("Preorder Traversal:\n");
    Ipreorder(root);
    printf("\nInorder Traversal:\n");
    inorder(root);
    printf("\nLevel order Traversal:\n");
    levelorder(root);*/
    printf("Count: %d\n",count(root));
    printf("Height: %d\n",height(root));
    return 0;
}
