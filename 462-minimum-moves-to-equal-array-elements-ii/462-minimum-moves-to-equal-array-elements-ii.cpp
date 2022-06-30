class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int n = nums.size();
        int mid = n/2, i = 0;
        for(i = 0 ; i< n;i++){
            count += abs(nums[i] - nums[mid]);
        }
        return count;
    }
};