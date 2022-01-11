class Solution {
public:
    int minCost(vector<int>&cost, int currentIndex,unordered_map<int,int>&mp){
        if(currentIndex == cost.size()){
            return 0;
        }
        
        if(currentIndex > cost.size()){
            return 1000;
        }
        
        int currentKey = currentIndex;
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        int oneJump = minCost(cost, currentIndex + 1,mp) + cost[currentIndex];
        int twoJump = minCost(cost, currentIndex + 2,mp) + cost[currentIndex];
        
        mp[currentKey] = min(oneJump,twoJump);
        
        return  mp[currentKey];
        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int>mp;
        int a = minCost(cost,0,mp);
        int b = minCost(cost,1,mp);
        return min(a,b);
    }
};