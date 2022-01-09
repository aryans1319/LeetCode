class Solution {
public:
    int minCost(vector<int>&cost, int currentIndex, unordered_map<int,int>&memo){
        
        if(currentIndex == cost.size()){
            return 0;
        }
        
        if(currentIndex > cost.size()){
            return 1001;
        }
        
        int currentKey = currentIndex;
        
        if(memo.find(currentKey)!= memo.end()){
            return memo[currentKey];
        }
        
        int oneJump = minCost(cost, currentIndex + 1,memo) + cost[currentIndex];
        int twoJumps = minCost(cost, currentIndex + 2,memo) + cost[currentIndex];
        
        memo[currentKey] = min(oneJump,twoJumps);
        
        return memo[currentKey];
    }
    
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int>memo;
        int costFromIndex0 = minCost(cost,0,memo);
        int costFromIndex1 = minCost(cost,1,memo);
        
        return min(costFromIndex0,costFromIndex1);
    }
};