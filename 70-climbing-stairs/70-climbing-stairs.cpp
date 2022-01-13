class Solution {
public:
    
    int totalWays(int targetStair, int currentStair){
        
        // Base Conditions
        
        if(currentStair == targetStair){
            return 1;
        }
        
        if(currentStair > targetStair){
            return 0;
        }
        
        int prev2 = 1;
        int prev = 1;
        
        for(int i=2;i<=targetStair;i++){
            int cur_i = prev2 + prev;
            prev2=prev;
            prev=cur_i;
        }
        return  prev;
        
    }
       
    int climbStairs(int n) {
        return totalWays(n,0);
    }
};