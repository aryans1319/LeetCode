class Solution {
public:
    int dp[101][100001];
    int minNumberOfCoins(vector<int>&coins, int currentIndex, int amount){
        
        if(amount == 0){
            return 0;
        }
        
        if(currentIndex >= coins.size()){
            return 100001;
        }
        
        if(dp[currentIndex][amount]!=-1){
            return dp[currentIndex][amount];
        }
        
        int pick = 100001 ;
        if(coins[currentIndex] <= amount){
            pick = 1+ minNumberOfCoins(coins, currentIndex, amount - coins[currentIndex]);
        }
        
        int notPick = minNumberOfCoins(coins,currentIndex+1,amount);
        
        dp[currentIndex][amount] = min(pick,notPick);
        
        return  dp[currentIndex][amount];

    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = minNumberOfCoins(coins,0,amount);
        if(ans == 100001){
            return -1;
        }
        return ans;
    }
};