class Solution {
public:
    int countWays(int currentStair, int targetStair,unordered_map<int,int>&mp){
        if(currentStair == targetStair){
            return 1;
        }
        
        if(currentStair > targetStair){
            return 0;
        }
        
        int currentKey = currentStair;
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        int oneStep = countWays(currentStair+1 , targetStair,mp);
        int twoStep = countWays(currentStair+2 , targetStair,mp);
        
        mp[currentKey] = oneStep + twoStep;
        return mp[currentKey];
    }
    
    
    int climbStairs(int n) {
        unordered_map<int,int>mp;
        return countWays(0,n,mp);
    }
};