import java.util.*;

public class removeLargestNcols
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r=sc.nextInt(), c = sc.nextInt();
        int[][] a = new int[r][c];
        int[] sum = new int[c];
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                a[i][j] = sc.nextInt();
                sum[j] += a[i][j];
            }
        }
        int del=sc.nextInt();
        int[][] arr = new int[c][2];
        for(int i=0; i<c; i++){
            arr[i] = new int[]{i,sum[i]};
        }
        for(int i=0; i<c; i++){
            System.out.println(arr[i][0] +" "+ arr[i][1]);
        }
        Arrays.sort(arr,(x,y)->y[1]-x[1]);
        Set<Integer> set = new HashSet<>();
        for(int i=0; i<del; i++){
            set.add(arr[i][0]);
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(set.contains(j)) continue;
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
        sc.close();
    }
}