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
    printf("Enter non-zero elements:\n");
    for(int i=0; i<s->non_zero; i++){
        scanf("%d %d %d",&s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

struct Sparse* add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum = (struct Sparse*)malloc(sizeof(struct Sparse));
    int i, j, k;
    i=j=k=0;
    sum->e = (struct Element*)malloc(sizeof(struct Element)*(s1->non_zero + s2->non_zero));

    while(i < s1->non_zero && j < s2->non_zero)
    {
        if(s1->e[i].i < s2->e[j].i){
            sum->e[k++] = s1->e[i++];
        }
        else if(s1->e[i].i > s2->e[j].i){
            sum->e[k++] = s2->e[j++];
        }
        else{
            if(s1->e[i].j < s2->e[j].j){
                sum->e[k++] = s1->e[i++];
            }
            else if(s1->e[i].j > s2->e[j].j){
                sum->e[k++] = s2->e[j++];
            }
            else{
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }

    for(; i<s1->non_zero; i++)  sum->e[k++] = s1->e[i];
    for(; j<s2->non_zero; j++)  sum->e[k++] = s2->e[j];
    sum->m = s1->m;
    sum->n = s1->n;
    sum->non_zero = k;
    return sum;
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
    struct Sparse s1, s2, *sum;
    create(&s1);
    create(&s2);
    sum = add(&s1,&s2);
    printf("First Matrix:\n");
    Display(s1);
    printf("Second Matrix:\n");
    Display(s2);
    printf("Sum Matrix:\n");
    Display(*sum);
    return 0;
}