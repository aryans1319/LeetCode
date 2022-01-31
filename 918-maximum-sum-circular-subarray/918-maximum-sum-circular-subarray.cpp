class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // int res=nums[0];
        // for(int i=0;i<nums.size();i++){
        //     int curr_max=nums[i];
        //     int curr_sum=nums[i];
        //     for(int j=1;j<nums.size();j++){
        //         int index=(i+j)%nums.size();
        //         curr_sum+=nums[index];
        //         curr_max=max(curr_max,curr_sum);
        //     }
        //     res=max(res,curr_max);
        // }
        // return res;
            if(nums.size() == 0) return 0;
        int sum = nums[0];
        int maxSoFar = nums[0];
        int maxTotal = nums[0];
        int minSoFar = nums[0];
        int minTotal = nums[0];
        for(int i = 1; i< nums.size();i++){
            maxSoFar = max(nums[i], maxSoFar + nums[i]);
            maxTotal = max(maxTotal, maxSoFar);
            
            minSoFar = min(nums[i], minSoFar + nums[i]);
            minTotal = min(minTotal, minSoFar);
            sum += nums[i];

        }
        if(sum == minTotal) return maxTotal;
        return max(sum - minTotal, maxTotal);
    }
};