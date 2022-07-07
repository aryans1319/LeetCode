class Solution {
public:
     void generateAllSubsets(vector<int>&nums, int currentIndex, vector<int>&sub,vector<vector<int>>&allSubsets){
         if(currentIndex >= nums.size()){
             allSubsets.push_back(sub);
             return;
         }
         
         sub.push_back(nums[currentIndex]);
         generateAllSubsets(nums,currentIndex +1,sub,allSubsets);
         sub.pop_back();
         generateAllSubsets(nums,currentIndex +1,sub,allSubsets);
         return;
     }
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>allSubsets;
        vector<int>sub;
        generateAllSubsets(nums,0,sub,allSubsets);
        return allSubsets;
    }
};