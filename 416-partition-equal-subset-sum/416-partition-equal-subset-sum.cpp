class Solution {
public:
    bool isPossible(vector<int>&nums, int currentIndex, int targetSum,unordered_map<string,bool>&mp)
    {
        if(targetSum == 0){
            return true;
        }
        
        if(currentIndex >= nums.size()){
            return false;
        }
        
        string currentKey = to_string(currentIndex) + "_" + to_string(targetSum);
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        bool consider = false;
        if(nums[currentIndex] <= targetSum){
        consider = isPossible(nums, currentIndex + 1, targetSum - nums[currentIndex],mp);
        }
        if(consider){
            mp[currentKey] = consider;
            return true;
        }
        
        bool notConsider = isPossible(nums,currentIndex+1,targetSum,mp);
        mp[currentKey] = consider || notConsider;
        return      mp[currentKey];
    }
    
    
    
    bool canPartition(vector<int>& nums) {
        int targetSum = 0;
        for(auto i : nums){
            targetSum+=i;
        }
        if(targetSum%2!=0){
            return false;
        }
        unordered_map<string,bool>mp;
        return isPossible(nums,0,targetSum/2,mp);
    }
};