/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.



Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]
Example 4:

Input: nums = [9,11], k = 2
Output: [11]

*/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int>ans;
        deque<pair<int, int>>dq;
        int i;
        for (i = 0; i < k; ++i) {
            while ((!dq.empty()) && nums[i] >= dq.back().first)
                dq.pop_back();

            dq.push_back({ nums[i],i });

        }

        while (i < nums.size()) {
            ans.push_back(dq.front().first);
            while (!dq.empty() && dq.front().second <= i - k) {
                dq.pop_front();

            }

            while (!dq.empty() && dq.back().first <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back({ nums[i], i });

            ++i;
        }
        ans.push_back(dq.front().first);
        return ans;
    }
};