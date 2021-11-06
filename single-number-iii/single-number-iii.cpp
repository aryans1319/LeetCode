class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>v;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto it: mp){
            if(it.second==1)
                v.push_back(it.first);
        }
        return v;
    }
};