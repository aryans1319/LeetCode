class Solution {
public:
    void generateCombinations(vector<int>&candidates, int currentIndex, int target, vector<int>&currentCombo,vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(currentCombo);
            return;
        }
        
        if(currentIndex >= candidates.size()){
            return;
        }
        
        int currentVal = candidates[currentIndex];
        if(target >= currentVal){
            currentCombo.push_back(currentVal);
            generateCombinations(candidates, currentIndex, target - currentVal, currentCombo, ans);
            currentCombo.pop_back();
        }
        generateCombinations(candidates, currentIndex + 1, target, currentCombo, ans);
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>currentCombo;
        generateCombinations(candidates, 0, target,currentCombo,ans);
        return ans;
    }
};