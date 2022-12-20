#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node
{
    int coeff, exp;
    struct Node *next;
}*poly=NULL;

void create()
{
    struct Node *t, *last;
    int num;
    printf("Enter the number of terms:\n");
    scanf("%d",&num);
    printf("Enter each term with coeff and exp:\n");
    for(int i=0; i<num; i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d %d",&t->coeff,&t->exp);
        t->next = NULL;
        if(poly==NULL){
            poly=last=t;
        }
        else{
            last->next=t;
            last = t;
        }
    }   
}

void display()
{
    struct Node *p=poly;
    printf("The polynomial:\n");
    while(p){
        printf("%dx%d +",p->coeff,p->exp);
        p=p->next;
    }
}

long eval(int x)
{
    long sum=0;
    struct Node *p = poly;
    while(p){
        sum += p->coeff * pow(x,p->exp);
        p = p->next;
    }
    return sum;
}

int main()
{
    create();
    display();
    printf("\nThe result is %ld",eval(1));
}