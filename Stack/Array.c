#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int* arr;
};

void create(struct stack *st)
{
    printf("Enter the size of stack:\n");
    scanf("%d",&st->size);
    st->top = -1;
    st->arr =(int*)malloc(sizeof(int)*st->size);
}

void display(struct stack st)
{
    for(int i=st.top; i>=0; i--){
        printf("%d ",st.arr[i]);
    }
    printf("\n");
}

void push(struct stack *st, int val)
{
    if(st->top == st->size-1){
        printf("Stack OverFlow\n");
    }
    else{
        st->top++;
        st->arr[st->top] = val;
    }
}

int pop(struct stack *st)
{
    int x=-1;
    if(st->top == -1){
        printf("Stack UnderFlow\n");
    }
    else{
        x = st->arr[st->top--];
    }
    return x;
}

int peek(struct stack st, int index)
{
    int x=-1;
    if(st.top-index+1 < 0){
        printf("Invalid Index\n");
    }
    x = st.arr[st.top-index+1];
    return x;
}

int isEmpty(struct stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}

int isFull(struct stack st)
{
    if(st.top == st.size-1)
        return 1;
    return 0;
}

int stackTop(struct stack st)
{
    if(!isEmpty(st)){
        return st.arr[st.top];
    }
    return -1;
}

int main()
{
    struct stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);

    printf("%d\n",isFull(st));

    display(st);
}