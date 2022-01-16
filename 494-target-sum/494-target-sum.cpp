class Solution {
public:
    int totalWays(vector<int> &nums, int target,int currentIndex){
        int n=nums.size();
        if(currentIndex >= n && target!=0)
            return 0;
        if(currentIndex >= n && target==0)
            return 1;
        
        int posSign = totalWays(nums, target-nums[currentIndex] , currentIndex+1);
        int negSign = totalWays(nums, target+nums[currentIndex] , currentIndex+1);
        
        return posSign+negSign;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return totalWays(nums,target,0);
    }
};