class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size() - 1;
        int maxi = INT_MIN;
        while(start <= end){
            int currentSum = nums[start] + nums[end];
            maxi = max(maxi, currentSum);
            start++;end--;
        }
        return maxi;
    }
};