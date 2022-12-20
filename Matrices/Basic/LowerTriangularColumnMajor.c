#include<stdio.h>
#include<stdlib.h>
struct Matrix
{
    int *A;
    int n;
};

void set(struct Matrix *m, int i, int j, int val)
{
    if(i>=j)
        m->A[m->n*(j-1) - ((j-2)*(j-1)/2) + (i-j)] = val;
    
}

int get(struct Matrix m, int i, int j)
{
    if(i>=j)
        return m.A[m.n*(j-1) - ((j-2)*(j-1)/2) + (i-j)];
    else
        return 0;
}

void Display(struct Matrix m)
{
    for(int i=1; i<=m.n; i++){
        for(int j=1; j<=m.n; j++){
            if(i>=j)
                printf("%d ",m.A[m.n*(j-1) - ((j-2)*(j-1)/2) + (i-j)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    int val;
    printf("Enter Dimension:\n");
    scanf("%d",&m.n);
    m.A = (int*)malloc(sizeof(int) * m.n*(m.n+1)/2);
    printf("Enter all elements:\n");
    for(int i=1; i<=m.n; i++){
        for(int j=1; j<=m.n; j++){
            scanf("%d",&val);
            set(&m, i, j, val);
        }
    }
    Display(m);
    return 0;
}