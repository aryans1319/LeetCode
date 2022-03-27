class Solution {
public:
    int totalWays(int n,vector<int>&dp){
        if(n == 0) return 1; 
        if(n==1) return 1;
        
        if(dp[n]!=-1){
            return dp[n];
        }
        int oneJump = totalWays(n-1,dp);
        int twoJump = totalWays(n-2,dp);
        dp[n] = oneJump + twoJump;
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ans = totalWays(n,dp);
        return ans;
    }
};