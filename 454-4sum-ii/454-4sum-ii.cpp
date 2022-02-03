class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>mp;
        for(auto i: nums3){
            for(auto j: nums4){
                mp[i+j]++;
            }
        }
        int count =0;
        for(auto c: nums1){
            for(auto d : nums2){
                int x = c+d;
                if(mp[-x]){
                    count += mp[-x];
                }
            }
        }
        return count;
    }
};