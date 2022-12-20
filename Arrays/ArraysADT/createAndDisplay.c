#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int* A;
    int size, length;
};
void Display(struct Array arr)
{
    printf("The elements in Array are:\n");
    for(int i=0; i<arr.length; i++){
        printf("%d ",arr.A[i]);
    }
}


int main()
{
    struct Array arr;
    int n;
    printf("Enter the size of an Array:\n");
    scanf("%d",&arr.size);
    arr.A = (int*)malloc(arr.size*sizeof(int));
    arr.length=0;

    printf("Enter number of elements:\n");
    scanf("%d",&n);

    printf("Enter all elements:\n");
    for(int i=0; i<n; i++){
        scanf("%d",&arr.A[i]);
    }
    arr.length=n;
    Display(arr);
}