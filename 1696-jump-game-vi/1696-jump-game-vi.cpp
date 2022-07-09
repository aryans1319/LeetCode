class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(size(nums), INT_MIN);
    multiset<int> s ({ dp[0] = nums[0] });         // set dp[0] = nums[0] and insert it into set
	for(int i = 1; i < size(nums); i++) {
        if(i > k) s.erase(s.find(dp[i - k - 1]));  // erase elements from which we cant jump to current index
        s.insert(dp[i] = *rbegin(s) + nums[i]);    // choose element with max score and jump from that to the current index
    }
	return dp.back();

    }
};