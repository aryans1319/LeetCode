class Solution {
public:
    void generateUniqueCombinations(vector<int>& candidates,int currentIndex, int target, vector<int>&currentCombo, vector<vector<int>>&ans){
        
        if(target == 0){
            ans.push_back(currentCombo);
            return;
        }
        
        if(currentIndex >= candidates.size()){
            return;
        }
        
        int currentVal = candidates[currentIndex];
        
        if(currentVal <= target){
            currentCombo.push_back(currentVal);
            generateUniqueCombinations(candidates, currentIndex + 1, target-currentVal, currentCombo, ans);
            currentCombo.pop_back();
            while(currentIndex + 1 < candidates.size() && candidates[currentIndex + 1] == candidates[currentIndex]) currentIndex++;
        }
        
        generateUniqueCombinations(candidates, currentIndex + 1, target, currentCombo, ans);
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>currentCombo;
        sort(candidates.begin(),candidates.end());
        generateUniqueCombinations(candidates, 0, target,currentCombo,ans);
        return ans;
    }
};