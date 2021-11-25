class Solution {
public:
    int bestTime(vector<int>&prices,int currentDay,bool canBuy,int transCount,vector<vector<vector<int>>>&dp){
        if(currentDay >= prices.size() || transCount<=0){
            return 0;
        }
        
        if(dp[currentDay][canBuy][transCount]!=-1)
        {
            return dp[currentDay][canBuy][transCount];
        }
        
        int idle = bestTime(prices, currentDay+1, canBuy,transCount,dp);
        int buy,sell;
        if(canBuy){

buy = -prices[currentDay] + bestTime(prices, currentDay+1,0,transCount,dp);
          dp[currentDay][canBuy][transCount] = max(idle,buy);
        return dp[currentDay][canBuy][transCount];
        }
        else{
            sell = prices[currentDay] + bestTime(prices,currentDay+1, 1, transCount-1,dp);
           dp[currentDay][canBuy][transCount]  =max(idle,sell);
            return  dp[currentDay][canBuy][transCount];
        }
     }
    
    int maxProfit(vector<int>& prices) {
         vector<vector<vector<int> > > dp (prices.size(),vector<vector<int> >(3,vector <int>(3,-1)));
        return bestTime(prices,0,1,2,dp);
    }
};