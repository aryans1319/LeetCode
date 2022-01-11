class Solution {
public:
    int maxAmountOfMoneyRobbed(vector<int>&nums, int currentIndex,unordered_map<int,int>&mp){
        
        if(currentIndex >= nums.size()){
            return 0;
        }
        
        int currentKey = currentIndex;
        
         if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        int rob = maxAmountOfMoneyRobbed(nums, currentIndex + 2,mp) + nums[currentIndex];
        
        int notRobbed = maxAmountOfMoneyRobbed(nums, currentIndex + 1,mp);
        
        mp[currentKey] = max(rob,notRobbed);
        return  mp[currentKey];
    }
    
    
    
    
    int rob(vector<int>& nums) {
        unordered_map<int,int>mp;
        return maxAmountOfMoneyRobbed(nums,0,mp);
    }
};