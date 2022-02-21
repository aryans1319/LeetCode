class Solution {
public:
    int majorityElement(vector<int>& nums) {
         unordered_map<int,int>mp;int ans;
        for(auto i: nums){
            mp[i]++;
        }
        for(auto it : mp){
            if(it.second>nums.size()/2)
                ans= it.first;
        }
        return ans;
    }
};