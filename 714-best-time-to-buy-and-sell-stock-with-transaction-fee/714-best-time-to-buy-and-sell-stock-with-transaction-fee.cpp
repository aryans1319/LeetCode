class Solution {
public:
    int dp[50001][2];
    int bestTime(vector<int>&prices, int currentDay, bool canBuy,int fee){
        if(currentDay >= prices.size()){
            return 0;
        }
        
        if(dp[currentDay][canBuy]!=-1){
            return dp[currentDay][canBuy];
        }
        int idle = bestTime(prices,currentDay+1,canBuy,fee);
        int buy=0,sell=0;
        if(canBuy){
             buy = -prices[currentDay] + bestTime(prices,currentDay+1,0,fee);
            dp[currentDay][canBuy] =  max(buy,idle);
            return  dp[currentDay][canBuy];
        }
        else{
            sell = -fee + bestTime(prices,currentDay+1,1,fee)+prices[currentDay];
            dp[currentDay][canBuy] =  max(sell,idle);
            return  dp[currentDay][canBuy];
        }
    }
    int maxProfit(vector<int>& prices,int fee) {
        memset(dp,-1,sizeof(dp));
        return bestTime(prices,0,1,fee);
    }
};