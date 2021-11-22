class Solution {
public:
    int minCost(vector<int> &cost, int currentIndex,unordered_map<int,int> &memo){
        if(currentIndex == cost.size())
            return 0;
        
        if(currentIndex > cost.size())
            return 1000;
        
        int currentKey = currentIndex;
        
        if(memo.find(currentKey) != memo.end()){
            return memo[currentKey];
        }
        
        int oneJump = cost[currentIndex] + minCost(cost , currentIndex+1,memo);
        int twoJumps = cost[currentIndex] + minCost(cost, currentIndex+2, memo);
        
        memo[currentKey] = min(oneJump, twoJumps);
        
        return memo[currentKey];
    }
    
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        unordered_map<int,int> memo;
        int a = minCost(cost, 0 , memo);
        int b = minCost(cost, 1, memo);
        
        return min(a,b);
    }
};