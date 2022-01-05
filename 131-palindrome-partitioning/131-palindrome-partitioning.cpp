class Solution {
public:
    vector<vector<string>> partition(string s) {
            auto res = vector<vector<string>>();
        auto path = vector<string>();
        backtrack(s, 0, path, res);
        return res;
    }
    
    void backtrack(string &s, int start, vector<string> &path, vector<vector<string>> &res) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        
        for (int end = start + 1; end <= s.size(); ++end) {
			// [start, end)
            if (isPalindrome(s, start, end)) {
                string sub = s.substr(start, end - start);
                path.push_back(sub);
                backtrack(s, end, path, res);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string_view s, int start, int end) {
        for (int i = start, j = end - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};