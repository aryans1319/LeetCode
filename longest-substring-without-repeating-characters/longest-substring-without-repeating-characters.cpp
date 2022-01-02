class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int i=0,j=0;
    int mx = 0;
    unordered_map<char,int> memo;
    while(j<s.length()){
        memo[s[j]]++;
       
         if(memo.size()<j-i+1){
            while(memo.size()<j-i+1){
                memo[s[i]]--;
                if(memo[s[i]]==0)
                {
                    memo.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        
         if(memo.size()==j-i+1){
            mx = max(mx,j-i+1);
            j++;
        }
    }
    return mx;
    }
};