class Solution {
public:
    int minStartValue(vector<int>& nums) {
           int ans = 0, sum = 0;
        for(auto el : nums)
            sum += el, ans = min(ans, sum);
        return -ans+1;
    }
};