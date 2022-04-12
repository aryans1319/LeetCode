class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0;
        int len = 0;
        
        unordered_map<char,int>mp;
        int n = s.size();
        for(int right = 0;right < n;right++){
            char currentChar = s[right];
            if(mp.find(currentChar)!=mp.end() && mp[currentChar] >= left){
               left = mp[currentChar]+1;
            }
            len = right - left + 1;
            mp[currentChar] = right;
            ans = max(ans,len);
        }
        return ans;
    }
};