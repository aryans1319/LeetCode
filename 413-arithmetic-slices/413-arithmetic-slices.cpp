class Solution {
public:
     
    int memo(vector<int> nums, int n, int s,unordered_map<int,int>&mp){
        if(n < 3) return 0;
        if(mp.find(n) != mp.end()) 
            return mp[n];
        if(nums[n-3]-nums[n-2] == nums[n-2]-nums[n-1]) 
            return mp[n] = s+memo(nums, n-1, s+1,mp);
        else 
            return mp[n] = memo(nums, n-1, 1,mp);
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
          unordered_map<int,int>mp;
          return memo(nums, nums.size(), 1, mp);
    }
};