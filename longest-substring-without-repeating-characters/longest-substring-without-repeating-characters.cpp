class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           int i=0,j=0,ans=0;
        int n=s.size();
        unordered_map<char,int>mp;
        while(j<n)
        {
            mp[s[j]]++;
            
            if(mp.size()<j-i+1)
            {
                while(mp.size()<j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
            if(mp.size()==j-i+1)   //HERE YOU CAN ELSE AS WELL !!
            {
                ans=max(ans,j-i+1);
                j++;
            }
            
        }
        return ans;
    }
};