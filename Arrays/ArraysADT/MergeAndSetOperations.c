#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int size,length;
};

struct Array* Merge(struct Array* a1, struct Array* a2)
{
    struct Array* a3 =(struct Array*)malloc(sizeof(struct Array));
    int i=0,j=0,k=0;
    while(i<a1->length && j<a2->length){
        if(a1->A[i] < a2->A[j]){
            a3->A[k++] = a1->A[i++];
        }
        else{
            a3->A[k++] = a2->A[j++];
        }
    }
    for(; i<a1->length; i++){
        a3->A[k++] = a1->A[i];
    }
    for(; j<a2->length; j++){
        a3->A[k++] = a2->A[j];
    }
    a3->length = a1->length + a2->length;
    a3->size = 10;
    return a3;
}

struct Array* Union(struct Array* a1, struct Array* a2)
{
    struct Array* a3 =(struct Array*)malloc(sizeof(struct Array));
    int i=0,j=0,k=0;
    while(i<a1->length && j<a2->length){
        if(a1->A[i] < a2->A[j]){
            a3->A[k++] = a1->A[i++];
        }
        else if(a2->A[j] < a1->A[i]){
            a3->A[k++] = a2->A[j++];
        }
        else{
            a3->A[k++] = a1->A[i++];
            j++;
        }
    }
    for(; i<a1->length; i++){
        a3->A[k++] = a1->A[i];
    }
    for(; j<a2->length; j++){
        a3->A[k++] = a2->A[j];
    }
    a3->length = k;
    a3->size = 10;
    return a3;
}

struct Array* Intersection(struct Array* a1, struct Array* a2)
{
    struct Array* a3 =(struct Array*)malloc(sizeof(struct Array));
    int i=0,j=0,k=0;
    while(i<a1->length && j<a2->length){
        if(a1->A[i] < a2->A[j]){
            i++;
        }
        else if(a2->A[j] < a1->A[i]){
            j++;
        }
        else{
            a3->A[k++] = a1->A[i++];
            j++;
        }
    }
    a3->length = k;
    a3->size = 10;
    return a3;
}


struct Array* Difference(struct Array* a1, struct Array* a2)
{
    struct Array* a3 =(struct Array*)malloc(sizeof(struct Array));
    int i=0,j=0,k=0;
    while(i<a1->length && j<a2->length){
        if(a1->A[i] < a2->A[j]){
            a3->A[k++] = a1->A[i++];
        }
        else if(a2->A[j] < a1->A[i]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    for(; i<a1->length; i++){
        a3->A[k++] = a1->A[i];
    }
    a3->length = k;
    a3->size = 10;
    return a3;
}


void Display(struct Array arr)
{
    printf("The elements in Array are:\n");
    for(int i=0; i<arr.length; i++){
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

int main()
{
    struct Array a1 = {{2,6,10,15,25},10,5};
    //struct Array a2 = {{3,4,7,18,20},10,5};
    struct Array a2 = {{3,6,7,15,20},10,5};
    struct Array* a3;
    //a3 = Merge(&a1,&a2);
    a3 = Union(&a1,&a2);
    printf("Union of 2 Arrays:\n");
    Display(*a3);
    a3 = Intersection(&a1,&a2);
    printf("Intersection of 2 Arrays:\n");
    Display(*a3);
    a3 = Difference(&a1,&a2);
    printf("Difference of 2 Arrays:\n");
    Display(*a3);
}