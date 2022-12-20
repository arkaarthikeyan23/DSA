#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(int val)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Stack is full\n");
    }
    else{
        temp->data = val;
        temp->next = top;
        top = temp;
    }
}

int pop()
{
    int x=-1;
    if(top==NULL){
        printf("Stack is empty\n");
    }
    else{
        struct node *temp=top;
        top = top->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

void display()
{
    struct node *temp = top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int isOperand(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return 0;
    return 1; 
}

int eval(char *postfix)
{
    int x1, x2, r;

    for(int i=0; postfix[i]!='\0'; i++){
        if(isOperand(postfix[i]))
            push(postfix[i]-'0'); //'3'-'0' => 51-48 => 3
        else{
            x2 = pop(); 
            x1 = pop();
            switch (postfix[i])
            {
                case '+': r = x1 + x2;  break;
                case '-': r = x1 - x2;  break;
                case '*': r = x1 * x2;  break;
                case '/': r = x1 / x2;  break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    char *postfix = "234*+82/-";
    printf("Result is %d",eval(postfix));
    return 0;
}