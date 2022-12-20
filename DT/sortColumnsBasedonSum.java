import java.util.*;
public class sortColumnsBasedonSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r=sc.nextInt();
        int c=sc.nextInt();
        int[][] mat = new int[r][c];
        int[] sum = new int[c];
        int[] col = new int[c];
        for(int i=0; i<r; i++){
          for(int j=0; j<c; j++){
            mat[i][j] = sc.nextInt();
            sum[j]+=mat[i][j];
          }
        }
        sc.close();
        for(int i=0; i<c; i++){
          col[i]=i;
        }
        for(int i=0; i<r; i++){
          for(int j=i+1; j<c; j++){
            if(sum[i]>sum[j]){
              int t=sum[i];
              sum[i] = sum[j];
              sum[j] = t;
    
              t=col[i];
              col[i]=col[j];
              col[j]=t;
            }
          }
        }
        for(int i=0; i<r; i++){
          for(int j=0; j<c; j++){
            System.out.print(mat[i][col[j]]+" ");
          }
          System.out.println();
        }
      }
}
/*
3 3
5 1 6
4 2 9
8 7 3
o/p:
156
249
783
*/