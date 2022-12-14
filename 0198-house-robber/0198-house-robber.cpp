class Solution {
public:
  unordered_map<int,int>m;
    int maxMoney(vector<int>&nums, int currentHouse)
    {
          if(currentHouse>=nums.size())
            return 0;
        
         int currentCost=currentHouse;

        if(m.find(currentCost)!=m.end())
            return m[currentHouse];
        
        
        int rob=nums[currentHouse]+maxMoney(nums, currentHouse+2);
        int norob=maxMoney(nums, currentHouse+1);
                
        m[currentHouse]=max(rob,norob);
        return max(rob,norob);
        
    }
    int rob(vector<int>& nums) 
    {
      return maxMoney(nums,0);        
    }
};