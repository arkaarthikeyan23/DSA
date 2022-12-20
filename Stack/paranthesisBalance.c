#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
}*top=NULL;

void push(char val)
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

char pop()
{
    char x=-1;
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
        printf("%c ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int isBalanced(char *exp)
{
    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            if(top==NULL){
                return 0;
            }
            pop();
        }
    }
    if(top==NULL)
        return 1;
    else
        return 0;
}

int main()
{
    char *exp = "((a+b)*(c-d))";
    printf("%d ",isBalanced(exp));
}