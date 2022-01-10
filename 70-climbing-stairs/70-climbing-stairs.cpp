class Solution {
public:
    int totalWays(int targetStair, int currentStair, unordered_map<int,int>&mp){
        
        // Base Conditions
        
        if(currentStair == targetStair){
            return 1;
        }
        
        if(currentStair > targetStair){
            return 0;
        }
        
        int currentKey = currentStair;
        
        //mp[3]  = ---> 1 + 0
        //mp[2] -->    2
        
        
        if(mp.find(currentKey)!=mp.end()){
           return mp[currentKey];
        }
        
        // Choices
        int oneJump = totalWays(targetStair, currentStair+1,mp);
        
        int twoJumps = totalWays(targetStair, currentStair+2,mp);
        
        mp[currentKey] = oneJump + twoJumps;
        
        return  mp[currentKey];
        
    }
       
    int climbStairs(int n) {
        unordered_map<int,int>mp;
        return totalWays(n,0,mp);
    }
};