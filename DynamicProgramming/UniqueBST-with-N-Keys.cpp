#include<iostream>
#include<vector>
using namespace std;

int solve(int N) {
    if (N == 0 || N == 1) return 1;
    
    vector<int> dp(N + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= i; j++) {
            int leftBST = dp[j - 1];
            int rightBST = dp[i - j];
            sum += (leftBST * rightBST);
        }
        dp[i] = sum;
    }
    return dp[N];
}

int main() {
    int N = 5;
    cout<<solve(N)<<endl;
    return 0;
}
