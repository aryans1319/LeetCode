class Solution {
public:
    int maxMoneyLooted(vector<int>&nums, int currentIndex,unordered_map<int,int>&mp){
        
        //base condition
        
        if(currentIndex >= nums.size()){
            return 0;
        }
        //choices
        int currentKey = currentIndex;
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        int lootenge = maxMoneyLooted(nums,currentIndex+2,mp) + nums[currentIndex];
        int nhiLootenge = maxMoneyLooted(nums,currentIndex+1,mp);
        
        mp[currentKey] = max(lootenge,nhiLootenge);
        
        return   mp[currentKey];
        
    }
    
    int rob(vector<int>& nums) {
        unordered_map<int,int>mp;
        return maxMoneyLooted(nums,0,mp);
    }
};