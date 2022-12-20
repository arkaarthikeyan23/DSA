#include<stdio.h>
#include<stdlib.h>

struct Term{
    int coeff, exp;
};

struct Poly{
    int n;
    struct Term *terms;
};

void create(struct Poly *p)
{
    printf("Enter the no. of. terms:\n");
    scanf("%d",&p->n);
    p->terms = (struct Term*)malloc(sizeof(struct Term)* p->n);
    printf("Enter terms:\n");
    for(int i=0; i<p->n; i++){
        scanf("%d %d",&p->terms[i].coeff,&p->terms[i].exp);
    }
}

struct Poly* add(struct Poly *p1, struct Poly *p2)
{
    struct Poly *sum = (struct Poly*)malloc(sizeof(struct Poly)*(p1->n + p2->n));
    int i,j,k;
    i=j=k=0;
    while(i<p1->n && j<p2->n){
        if(p1->terms[i].exp > p2->terms[j].exp){
            sum->terms[k++] = p1->terms[i++];
        }
        else if(p1->terms[i].exp < p2->terms[j].exp){
            sum->terms[k++] = p2->terms[j++];
        }
        else{
            sum->terms[k] = p1->terms[i];
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    for(; i<p1->n; i++) sum->terms[k++] = p1->terms[i];
    for(; j<p2->n; j++) sum->terms[k++] = p2->terms[j];
    sum->n=k;
    return sum;
}

void Display(struct Poly p)
{
    for(int i=0; i<p.n; i++){
        printf("%dx%d+",p.terms[i].coeff,p.terms[i].exp);
    }
    printf("\n");
}

int main()
{
    struct Poly p1, p2, *p3;
    create(&p1);
    create(&p2);
    p3=add(&p1,&p2);
    Display(p1);
    printf("\n");
    Display(p2);
    printf("\n");
    Display(*p3);
    return 0;
}