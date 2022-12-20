#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int isOperand(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return 0;
    return 1; 
}

int precedence(char ch)
{
    if(ch=='+' || ch=='-')
        return 1;
    else if(ch=='*' || ch=='/')
        return 2;
    return 0;
}

char* InToPost(char* infix)
{
    int len = strlen(infix);
    char *postfix = (char*) malloc(len+2);
    int i=0, j=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(precedence(infix[i]) > precedence(top->data))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }

    while(top!=NULL){
        postfix[j++] = pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char *infix = "a+b*c-d/e";
    push('#');
    char *postfix = InToPost(infix);
    printf("%s ",postfix);
    return 0;
}