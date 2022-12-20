#include <stdio.h>

int main(void) {
    int r,c;
    scanf("%d%d",&r,&c);
    int mat[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int sum=mat[0][0], row=0;
    for(int j=1; j<c; j++){
        int max=-1, maxr=0;
        if(row-1>=0 &&mat[row-1][j]>max){
            max = mat[row-1][j];
            maxr = row-1;
        }
        if(mat[row][j]>max){
            max = mat[row][j];
            maxr = row;
        }
        if(row+1<r && mat[row+1][j]>max){
            max = mat[row+1][j];
            maxr = row+1;
        }
        sum+=max;
        row=maxr;
    }
    printf("%d",sum);
}
/*
3 3 
2 55 40  
3 58 30
23 23 20
o/p
100
3 5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
o/p:
50
*/