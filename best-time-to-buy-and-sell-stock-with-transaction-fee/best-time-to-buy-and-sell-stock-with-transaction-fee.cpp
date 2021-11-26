class Solution {
public:
   int dp[50001][2];
    int bestTime(vector<int>&prices,int currentDay,bool canBuy,int fee){
        if(currentDay >= prices.size()){
            return 0;
        }
        
       // string currentKey = to_string(currentDay) +"_"+ to_string(canBuy) +"_" + to_string(transCount);
        
        
        // if(dp.find(currentKey)!=dp.end()){
        //     return dp[currentKey];
        // }
        
        if( dp[currentDay][canBuy]!=-1){
            return  dp[currentDay][canBuy];
        }
        int idle = bestTime(prices, currentDay+1, canBuy,fee);
        int buy=0,sell=0;
        if(canBuy==1){

buy = -prices[currentDay] + bestTime(prices, currentDay+1,0,fee);
     
          buy=     max(idle,buy);
        }
        else{
            sell = -fee+prices[currentDay] + bestTime(prices,currentDay+1, 1,fee);
            sell=max(idle,sell);
           
        }
         dp[currentDay][canBuy] =  max(buy,sell);
           return dp[currentDay][canBuy];         
    }
    int maxProfit(vector<int>& prices, int fee) {
         memset(dp,-1,sizeof(dp));
        return bestTime(prices,0,1,fee);
    }
};