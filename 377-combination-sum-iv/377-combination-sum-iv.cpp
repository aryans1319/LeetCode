class Solution {
public:
    int totalWays(vector<int>&nums, int currentIndex,int target,vector<int>&mp){
        if(currentIndex >= nums.size()|| target<=0){
            return (target==0) ? 1:0;
        }
      
        if(mp[target]!=-1){
            return mp[target];
        }
        int pick =  totalWays(nums,0, target - nums[currentIndex],mp);
        int notPick = totalWays(nums, currentIndex+1, target,mp);
        mp[target] = pick+notPick;
        return mp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>mp(target+1,-1);
        return totalWays(nums,0,target,mp);
    }
};