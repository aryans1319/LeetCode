class Solution {
public:
    int dp[5001][2];
    int bestTime(vector<int>&prices, int currentDay, bool canBuy){
        if(currentDay >= prices.size()){
            return 0;
        }
        
        if(dp[currentDay][canBuy]!=-1){
            return dp[currentDay][canBuy];
        }
        int idle = bestTime(prices,currentDay+1,canBuy);
        int buy=0,sell=0;
        if(canBuy){
             buy = -prices[currentDay] + bestTime(prices,currentDay+1,0);
            dp[currentDay][canBuy] =  max(buy,idle);
            return  dp[currentDay][canBuy];
        }
        else{
            sell = prices[currentDay] + bestTime(prices,currentDay+2,1);
            dp[currentDay][canBuy] =  max(sell,idle);
            return  dp[currentDay][canBuy];
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return bestTime(prices,0,1);
    }
};