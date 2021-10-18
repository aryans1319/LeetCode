/*******************************

45. Jump Game II

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. 
Jump 1 step from index 0 to 1, then 3 steps to the last index.

**********************************/


/************************CODE***********************/


class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0;
        int prev = -1;
        int curr = 0;
        int steps = nums[0];
        if(nums.size() == 1){
            return 0;
        }
        int cnt = 1;
        for(int i = 1 ; i < nums.size()-1 ; i++){
            steps--;
            if(prev != -1 && nums[i] > steps && i-prev <= nums[prev]){
                curr = i;
                steps = nums[i];
            }
            else if(nums[i] > steps){
                steps = nums[i];
                prev = curr;
                curr = i;
                cnt++;
            }
        }
        if(prev != -1 && nums.size()-1 - prev <= nums[prev]) cnt--;
        return cnt;
    }
};