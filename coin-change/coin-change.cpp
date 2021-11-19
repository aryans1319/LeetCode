class Solution {
public:
    int dp[101][100001];
    int minCoins(vector<int>&coins , int currentIndex , int amount){
        if(amount==0){
            return 0;
        }
        
        if(currentIndex >= coins.size()){
            return 100000;
        }
        
        if(dp[currentIndex][amount]!=-1){
            return dp[currentIndex][amount];
        }
        int consider = 100000;
        
        
        if(coins[currentIndex] <= amount){
    
    consider = 1 + minCoins(coins, currentIndex, amount- coins[currentIndex]);
        
        }
        
        int notConsider = minCoins(coins, currentIndex+1, amount);
        dp[currentIndex][amount]=min(consider, notConsider);
        return dp[currentIndex][amount];
       
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans =  minCoins(coins, 0 ,amount);
        if(ans==100000){
            return -1;
        }
        return ans;
    }
};