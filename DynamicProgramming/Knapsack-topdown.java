class Main {
    public static void main(String[] args) {
        int[] val = { 2, 3, 4, 1  };
        int[] wt = { 3, 4, 5, 6 };
        int W = 8;
        int result = knapsack(val, wt, W, val.length);
        System.out.println("Result-> " + result);
    }
    
    static int knapsack(int val[], int wt[], int W, int N) {
        int[][] dp = new int[N + 1][W + 1];
        for (int n = 0; n <= N; n++) {
            for (int w = 0; w <= W; w++) { 
                if (n == 0 || w == 0) {
                    dp[n][w] = 0;
                } else if (wt[n - 1] <= w) {
                    dp[n][w] = max((val[n - 1] + dp[n - 1][w - wt[n - 1]]), dp[n - 1][w]);
                } else {
                    dp[n][w] = dp[n - 1][w];
                }
            }
        }
        
        return dp[N][W];
    }
    
    static int max(int a, int b) {
        return (a > b) ? a : b;
    }
}
