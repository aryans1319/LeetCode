class Solution {
public:
     int findWays(vector<int>&coins , int currentIndex , int amount, unordered_map<string,int>&mp){
        if(amount==0){
            return 1;
        }
        
        if(currentIndex >= coins.size()){
            return 0;
        }
        
        string currentKey = to_string(currentIndex)+ "_" + to_string(amount);
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        int consider = 0;
        
        
        if(coins[currentIndex] <= amount){
    
    consider = findWays(coins, currentIndex, amount- coins[currentIndex],mp);
        
        }
        
        int notConsider = findWays(coins, currentIndex+1, amount,mp);
        mp[currentKey] = consider+notConsider;
        return mp[currentKey];
    }
    
    int change(int amount, vector<int>& coins) {
         unordered_map<string,int>mp;
        int ans =  findWays(coins, 0 ,amount,mp);
        
        // if(ans==100000){
        //     return -1;
        // }
        return ans;
    }
};