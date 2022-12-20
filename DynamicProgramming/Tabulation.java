public class Tabulation {
    public static void main(String[] args) {
        int[] weight = {3,2,4};
        int[] profit = {6,8,7};
        int bag = 8;
        int n = weight.length;
        int[][] dp = new int[n+1][bag+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=bag; j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(weight[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else 
                    dp[i][j] = Math.max(dp[i-1][j], profit[i-1]+dp[i-1][j-weight[i-1]]);
            }
        }
        System.out.println(dp[n][bag]);
    }
}
