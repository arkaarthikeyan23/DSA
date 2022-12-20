#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i, j, x;
};

struct Sparse
{
    int m, n, non_zero;
    struct Element *e;
};

void create(struct Sparse *s)
{
    printf("Enter the dimensions:\n");
    scanf("%d %d",&s->m, &s->n);
    printf("Enter the no. of. non-zero elements:\n");
    scanf("%d",&s->non_zero);
    s->e = (struct Element*)malloc(sizeof(struct Element)*(s->non_zero));
    printf("Enter all the elements:\n");
    for(int i=0; i<s->non_zero; i++){
        scanf("%d %d %d",&s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void Display(struct Sparse s)
{
    int k=0;
    for(int i=0; i<s.m; i++){
        for(int j=0; j<s.n; j++){
            if(i==s.e[k].i && j==s.e[k].j){
                printf("%d ",s.e[k++].x);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Sparse s;
    create(&s);
    Display(s);
    return 0;
}