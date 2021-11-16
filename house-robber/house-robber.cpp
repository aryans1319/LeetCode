class Solution {
public:
    int maxMoney(vector<int>&nums, int currentIndex, unordered_map<int,int>&mp){
        if(currentIndex >= nums.size()){
            return 0;
        }
        
        int currentKey = currentIndex;
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        int rob = nums[currentIndex]+maxMoney(nums, currentIndex+2,mp);
        int noRob = maxMoney(nums,currentIndex+1,mp);
        
        mp[currentKey] = max(rob,noRob);
        return mp[currentKey];
    }
    
    int rob(vector<int>& nums) {
        unordered_map<int,int>mp;
        return maxMoney(nums,0,mp);
    }
};