public class Memoization {
    public static int knapsack(int[] weight, int[] profit, int w, int n, int[][] mem){
        if(n==0 || w==0)
            return 0;
        if(mem[n-1][w-1]!=-1)
            return mem[n-1][w-1];
        int result;
        if(weight[n-1] > w)
            result = knapsack(weight, profit, w, n-1, mem);
        else
            result = Math.max(knapsack(weight, profit, w, n-1, mem), profit[n-1]+knapsack(weight, profit, w-weight[n-1], n-1, mem));
        return mem[n-1][w-1] = result;
    }

    public static void main(String[] args) {
        int[] weight = {3,2,4};
        int[] profit = {6,8,7};
        int bag = 8;
        int n = weight.length;
        int[][] mem = new int[n][bag];
        for(int i=0; i<n; i++){
            for(int j=0; j<bag; j++){
                mem[i][j] = -1;
            }
        }
        System.out.println(knapsack(weight,profit,bag,n,mem));
    }
}
