class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> copyArray(n);
        for(int i=0;i<n;i++){
            copyArray[(i+k)%n] = nums[i];
        }
        nums = copyArray;
    }
};