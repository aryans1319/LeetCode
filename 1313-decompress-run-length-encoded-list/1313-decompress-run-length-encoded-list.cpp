class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>ans;
        int i=0;
        while(i+1<nums.size()-i){
            int a = nums[2*i];
            int b = nums[2*i+1];
            while(a--){
                ans.push_back(b);
            }
            i++;
        }
        return ans;
    }
};