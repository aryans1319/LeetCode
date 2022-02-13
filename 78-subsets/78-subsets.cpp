class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet ;
        vector<int>currentSubset;
        generateAllSubsets(nums,0,currentSubset,powerSet);
        return powerSet;
    }
    
    void generateAllSubsets(vector<int>&nums, int currentIndex, vector<int>&currentSubset,vector<vector<int>>&powerSet){
        // passed by reference if we pass by value it would give us empty subsets 
        if(currentIndex >= nums.size()){
            powerSet.push_back(currentSubset);
            return;
        }
        
        int currentVal = nums[currentIndex];
        
        currentSubset.push_back(currentVal);
        generateAllSubsets(nums,currentIndex+1,currentSubset,powerSet);
        
        currentSubset.pop_back();
        generateAllSubsets(nums,currentIndex+1,currentSubset,powerSet);
        
        return;
        
    }
};