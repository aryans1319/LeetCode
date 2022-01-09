class Solution {
public:
    int totalWays(int targetStair, int currentStair,unordered_map<int,int>&mp){
        if(currentStair == targetStair){
            return 1;
        }
        
        if(currentStair > targetStair){
            return 0;
        }
        
        int currentKey = currentStair;
        
        if(mp.find(currentKey) != mp.end() ){
            return mp[currentKey];
        }
        
        int oneStep = totalWays(targetStair, currentStair+1,mp);
        int twoStep = totalWays(targetStair, currentStair+2,mp);
        
        mp[currentKey] = oneStep + twoStep;
        
        return mp[currentKey];
    }
    
    
    int climbStairs(int n) {
        unordered_map<int,int> mp;
        return totalWays(n,0,mp);
    }
};