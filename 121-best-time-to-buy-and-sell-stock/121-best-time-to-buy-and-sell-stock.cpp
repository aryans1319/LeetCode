class Solution {
public:
    int dp[100001][2][2];
    int bestTime(vector<int>&prices, int currentDay, bool canBuy, int transCount){
        if(currentDay >= prices.size() || transCount <=0){
            return 0;
        }
        
        if(dp[currentDay][canBuy][transCount]!=-1){
            return dp[currentDay][canBuy][transCount];
        }
        int idle = bestTime(prices,currentDay+1,canBuy,transCount);
        int buy=0,sell=0;
        if(canBuy){
             buy = -prices[currentDay] + bestTime(prices,currentDay+1, 0,transCount);
            dp[currentDay][canBuy][transCount] =  max(buy,idle);
            return  dp[currentDay][canBuy][transCount];
        }
        else{
            sell = prices[currentDay] + bestTime(prices,currentDay+1,1,transCount-1);
            dp[currentDay][canBuy][transCount] =  max(sell,idle);
            return  dp[currentDay][canBuy][transCount];
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return bestTime(prices,0,1,1);
    }
};