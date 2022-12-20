#include<stdio.h>
#include<stdlib.h>

int main()
{
    int A[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    int* B[3];
    for(int i=0; i<3; i++){
        B[i] = (int*)malloc(4*sizeof(int));
    }

    int **C;
    C =(int**) malloc(3*sizeof(int*));
    for(int i=0; i<3; i++){
        C[i] = (int*)malloc(4*sizeof(int));
    }
    printf("Enter the values of B:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            scanf("%d",&B[i][j]);
        }
    }
    printf("Enter the values of C:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            scanf("%d",&C[i][j]);
        }
    }

    printf("ARRAY A:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("ARRAY B:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    printf("ARRAY C:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
}