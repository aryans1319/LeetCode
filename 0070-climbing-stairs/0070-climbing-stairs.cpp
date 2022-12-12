class Solution {
public:
    int totalWays(int n, vector<int>&dp){
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        int oneStep = totalWays(n-1,dp);
        int twoStep = totalWays(n-2,dp);
        dp[n] = oneStep + twoStep;
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return totalWays(n,dp);
    }
};