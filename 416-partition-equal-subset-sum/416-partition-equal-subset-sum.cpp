class Solution {
public:
    bool isPossibleToForm(vector<int>&nums,int currentIndex, int target,unordered_map<string,bool>&mp){
        
        if(target==0){
            return true;
        }
        
        if(currentIndex >= nums.size()){
            return false;
        }
        string currentKey = to_string(currentIndex) + "_" + to_string(target);
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        bool pick = false;
        if(nums[currentIndex] <= target){
            pick = isPossibleToForm(nums, currentIndex+1,target-nums[currentIndex],mp);
        }
        if(pick){
            mp[currentKey] = true;
            return mp[currentKey];
        }
        bool notPick = isPossibleToForm(nums,currentIndex+1,target,mp);
        mp[currentKey] = pick || notPick;
        return mp[currentKey];
        
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums){
            sum+=i;
        }
        if(sum%2!=0){
            return false;
        }
        int target = sum/2;
        unordered_map<string,bool>mp;
        return isPossibleToForm(nums,0,target,mp);
    }
};