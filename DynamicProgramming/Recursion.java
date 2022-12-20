public class Recursion
{
    public static int knapsack(int[] weight, int[] profit, int w, int n){
        //base case
        if(w==0 || n==0)
            return 0;
        //skip case
        if(weight[n-1]>w)
            return knapsack(weight, profit, w, n-1);
        else
            return Math.max(knapsack(weight,profit,w,n-1) , profit[n-1]+ knapsack(weight, profit, w-weight[n-1], n-1));
    }
    public static void main(String[] args) {
        int[] weight = {3,2,4};
        int[] profit = {6,8,7};
        int bag = 8;
        int n = weight.length;
        System.out.println(knapsack(weight,profit,bag,n));
    }
}