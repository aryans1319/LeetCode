class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        
        for(auto it : nums){
            mp[it]++;
        }
        int ans;
        for(auto i : mp)
        if(i.second==1){
            ans = i.first;
            break;
        }
        return ans;
    }
};