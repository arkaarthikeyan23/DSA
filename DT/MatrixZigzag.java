import java.util.*;

public class MatrixZigzag
{
   public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R=sc.nextInt(), C=sc.nextInt();
        List<Integer> list = new ArrayList<>();
        int[][] mat = new int[R][C];
        int[] a = new int[7];
        int num=1, index=0;
        for(int i=0; i<7; i++){
            a[i] = sc.nextInt();
            while(a[i]-->0){
                list.add(num);
            }
            num++;
        }
        sc.close();
        for(int i=0; i<R; i++){
            if(i%2==0){
                for(int j=0; j<C; j++){
                    mat[i][j] = list.get(index++);
                }
            }
            else{
                for(int j=C-1; j>=0; j--){
                    mat[i][j] = list.get(index++);
                }
            }
        }
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                System.out.print(mat[i][j]+" ");
            }
            System.out.println();
        }
    }
}
/*4 4
1 2 1 4 2 3 3
o/p
1 2 2 3 
4 4 4 4 
5 5 6 6 
7 7 7 6 */