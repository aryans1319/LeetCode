class Solution {
public:
    
    int totalWays(int targetStair, int currentStair,unordered_map<int,int>&mp){
        
        // Base Conditions
        mp[0]=1;
        mp[1]=1;
        // mp[1] = 1;
        
        for(int i=2;i<=targetStair;i++){
            mp[i] = mp[i-1] + mp[i-2];
        }
        return  mp[targetStair];
        
    }
       
    int climbStairs(int n) {
        unordered_map<int,int>mp;
        return totalWays(n,0,mp);
    }
};