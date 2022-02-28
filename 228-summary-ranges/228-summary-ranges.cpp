class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
         vector<string> ans;
        if (!nums.size()) return ans;
        int f = nums[0], s = nums[0], len = nums.size();
        for (int i = 1; i < len; i++)
            if (s + 1 == nums[i])
                s = nums[i];
            else
                f == s ? ans.push_back(to_string(f)) : ans.push_back(to_string(f) + "->" + to_string(s)), f = s = nums[i];
        f == s ? ans.push_back(to_string(f)) : ans.push_back(to_string(f) + "->" + to_string(s));
        return ans;
    }
};