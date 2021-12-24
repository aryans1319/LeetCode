class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans;
        for(auto i: nums){
            m[i]++;
        }
        for(auto it: m){
            if(it.second> floor(nums.size()/2))
                ans=it.first;
        }
        return ans;
    }
};