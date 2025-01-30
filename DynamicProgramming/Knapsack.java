class Main {
    public static void main(String[] args) {
        int[] val = { 2, 3, 4, 1  };
        int[] wt = { 3, 4, 5, 6 };
        int W = 8;
        
        for (int i = 0; i < val.length + 1; i++) {
            for (int j = 0; j < W + 1; j++) { 
                dp[i][j] = -1;
            }
        }
        
        int result = knapsack(val, wt, W, val.length);
        System.out.println("Result-> " + result);
    }
    
    // int[][] dp = new int[n+1][W+1]
    static int[][] dp = new int[5][9];
    
    static int knapsack(int val[], int wt[], int W, int n) {
        if (n == 0 || W == 0) return 0;
        if (dp[n][W] != -1) return dp[n][W];
        if (wt[n - 1] <= W) {
            return dp[n][W] = max((val[n - 1] + knapsack(val, wt, W - wt[n - 1], n - 1)), knapsack(val, wt, W, n - 1));
        } else {
            return dp[n][W] = knapsack(val, wt, W, n - 1);
        }
    }
    
    static int max(int a, int b) {
        return (a > b) ? a : b;
    }
}
