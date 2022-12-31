class Solution {
public:
    void getAllCombinations(int currentIndex, int sum, int k, vector<int>&currentAns, vector<vector<int>>&totalCombinations){
        if(sum == 0 && currentAns.size() == k){
            totalCombinations.push_back(currentAns);
        }
        for(int i = currentIndex; i <= 9; i++){
            currentAns.push_back(i);
            getAllCombinations(i + 1, sum-i, k, currentAns, totalCombinations);
            currentAns.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>currentAns;
        getAllCombinations(1, n, k, currentAns, ans);
        return ans;
    }
};