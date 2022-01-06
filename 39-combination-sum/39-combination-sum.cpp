class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>answer;
        vector<int>currentAns;
        generateTotalWays(candidates,0,target,currentAns,answer);
        return answer;
    }
    
    void generateTotalWays(vector<int>&nums, int currentIndex, 
    int target,vector<int>&currentAns,vector<vector<int>>&answer){
        if(target == 0){
            answer.push_back(currentAns);
            return;
        }
        
        if(currentIndex >= nums.size()){
            return;
        }
        
        int currentVal = nums[currentIndex];
        
        if(target >= currentVal){
        currentAns.push_back(currentVal);
        generateTotalWays(nums,currentIndex,target-currentVal,currentAns,answer);
        currentAns.pop_back();
        }
        generateTotalWays(nums,currentIndex+1,target,currentAns,answer);
        return;
    }
};