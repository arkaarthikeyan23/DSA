#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int size, length;
};

void Append(struct Array *arr, int val)
{
    if(arr->length < arr->size){
        arr->A[arr->length++] = val;
    }
}

void Insert(struct Array *arr, int index, int val)
{
    if(index>=0 && index<arr->length){
        for(int i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index]=val;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    if(index>=0 && index<arr->length){
        int val =  arr->A[index];
        for(int i=index; i<arr->length-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return val;
    }
    return 0;
}

int LinearSearch(struct Array arr,int key)
{
    for(int i=0;i<arr.length; i++){
        if(arr.A[i]==key){
            return i;
        }
    }
    return -1;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int ImprovedLinearSearch(struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++){
        if(arr->A[i] == key){
            //swap(&arr->A[i],&arr->A[i-1]);  //Transpositioning
            swap(&arr->A[i],&arr->A[0]);     //Move to head method
            return i;
        }
    }
    return -1;
}

int BinSearch(struct Array arr, int key)
{
    int low=0, high=arr.length-1;
    while(low<high){
        int mid = (low+high)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

int RBinSearch(int arr[], int l, int h, int key)
{
    if(l<=h){
        int mid = (l+h)/2;
        if(key == arr[mid])
            return mid;
        else if(key < arr[mid])
            return RBinSearch(arr,l,mid-1,key);
        else
            return RBinSearch(arr,mid+1,h,key);
    }
    return -1;
}

void Display(struct Array arr)
{
    printf("The elements in Array are:\n");
    for(int i=0; i<arr.length; i++){
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

int Get(struct Array arr, int index)
{
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int val)
{
    if(index>=0 && index<arr->length){
        arr->A[index] = val;
    }
}

int Sum(struct Array arr)
{
    int sum=0;
    for(int i=0; i<arr.length; i++){
        sum = sum+arr.A[i];
    }
    return sum;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(arr.A[i]>max){
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(arr.A[i]<min){
            min = arr.A[i];
        }
    }
    return min;
}

void Reverse(struct Array *arr)
{
    //using Auxiliary Array
    int*B = (int*)malloc(arr->length * sizeof(int));
    for(int i=0, j=arr->length-1; i<arr->length; i++,j--){
        B[i] = arr->A[j];
    }
    for(int i=0; i<arr->length; i++){
        arr->A[i] = B[i];
    }
}

void inplaceReverse(struct Array* arr)
{
    for(int i=0, j=arr->length-1; i<j; i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}

void leftRotate(struct Array* arr)
{
    int val = arr->A[0];
    for(int i=1; i<arr->length; i++){
        arr->A[i-1] = arr->A[i]; 
    }
    arr->A[arr->length-1] = val;
}

void rightRotate(struct Array* arr)
{
    int val=arr->A[arr->length-1];
    for(int i=arr->length-1; i>=1; i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = val;
}

void insertSort(struct Array* arr, int val)
{
    if(arr->size == arr->length){
        return;
    }
    int index = arr->length-1;
    while(index>=0 && arr->A[index]>val){
        arr->A[index+1] = arr->A[index];
        index--;
    }
    arr->A[index+1] = val;
    arr->length++;
}

int isSorted(struct Array arr)
{
    for(int i=0; i<arr.length-1; i++){
        if(arr.A[i]>arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}

void RearrangeArray(struct Array* arr)
{
    int i=0, j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0){i++;}
        while(arr->A[j]>0){j--;}
        if(i<j){
            swap(&arr->A[i],&arr->A[j]);
        }
    }
}

int main()
{
    struct Array arr={{2,-9,3,-1,5,10,-8,15},10,8};
    //Append(&arr,10);
    //Insert(&arr,9,50);
    //printf("Array Length: %d\n",arr.length);
    //printf("Deleted element: %d\n",Delete(&arr,3));
    //printf("Array Length: %d\n",arr.length);
    //printf("Found at index: %d\n",LinearSearch(arr,6));
    //printf("Found at index: %d\n",ImprovedLinearSearch(&arr,6));
    //printf("Found at index: %d\n",ImprovedLinearSearch(&arr,6));
    //printf("Found at index: %d\n",RBinSearch(arr.A,0,arr.length,6));
    // printf("Element at index 4:%d\n",Get(arr,4));
    // Set(&arr,5,12);
    // printf("Maximum element is %d\n",Max(arr));
    // printf("Minimum element is %d\n",Min(arr));
    // printf("Sum of all elements is %d\n",Sum(arr));
    // printf("Average of all elements is %f\n",Avg(arr));
    //Display(arr);
    //printf("Reverse of all elements:\n");
    //inplaceReverse(&arr);
    //printf("After Left Rotation:\n");
    //leftRotate(&arr);
    //Display(arr);
    //printf("After Right Rotation:\n");
    //rightRotate(&arr);
    //insertSort(&arr,1);
    //printf("%d\n",isSorted(arr));
    // Display(arr);
    // printf("After Rearranging:\n");
    // RearrangeArray(&arr);
    Display(arr);
}