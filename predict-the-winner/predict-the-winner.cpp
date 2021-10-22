class Solution {
public:
    int game(int s,int e, vector<int>&nums){
        if(s>e){
            return 0;
        }
        else{
            int op1=nums[s]-game(s+1,e,nums);
            int op2=nums[e]-game(s,e-1,nums);
            return max(op1,op2);
        }
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int diff=game(0,nums.size()-1,nums);
        return diff>=0;
    }
};