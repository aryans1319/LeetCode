class Solution {
public:
    int subarraySum(vector<int>& nums, int goal){
           int currentSum = 0;
        unordered_map<int,int> mp;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            currentSum+=nums[i];
            
            if(currentSum == goal)
                count++;
            
            if(mp.find(currentSum - goal)!= mp.end()){
                count+=mp[currentSum-goal];
            }
            mp[currentSum]++;
        }
        return count;
    }
};