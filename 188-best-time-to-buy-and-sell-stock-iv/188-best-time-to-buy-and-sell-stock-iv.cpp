class Solution {
public:
    int dp[10001][2][101];
    int bestTime(vector<int>&prices,int currentDay,bool canBuy,int transCount){
        if(currentDay >= prices.size() || transCount<=0){
            return 0;
        }
        
       // string currentKey = to_string(currentDay) +"_"+ to_string(canBuy) +"_" + to_string(transCount);
        
        
        // if(dp.find(currentKey)!=dp.end()){
        //     return dp[currentKey];
        // }
        
        if( dp[currentDay][canBuy][transCount]!=-1){
            return  dp[currentDay][canBuy][transCount];
        }
        int idle = bestTime(prices, currentDay+1, canBuy,transCount);
        int buy=0,sell=0;
        if(canBuy==1){

buy = -prices[currentDay] + bestTime(prices, currentDay+1,0,transCount);
     
          buy=     max(idle,buy);
        }
        else{
            sell = prices[currentDay] + bestTime(prices,currentDay+1, 1, transCount-1);
            sell=max(idle,sell);
           
        }
         dp[currentDay][canBuy][transCount] =  max(buy,sell);
           return dp[currentDay][canBuy][transCount];         
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return bestTime(prices,0,1,k);
    }
};