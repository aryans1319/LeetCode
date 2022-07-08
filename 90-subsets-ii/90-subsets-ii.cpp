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
         while(currentIndex + 1 < nums.size() && nums[currentIndex + 1] == nums[currentIndex]) currentIndex++;
         generateAllSubsets(nums,currentIndex +1,sub,allSubsets);
         return;
     }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>allSubsets;
        vector<int>sub;
        sort(nums.begin(),nums.end());
        generateAllSubsets(nums,0,sub,allSubsets);
        return allSubsets;
    }
};