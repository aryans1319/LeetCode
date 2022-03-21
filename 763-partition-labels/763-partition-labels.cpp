class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mp;
        
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            mp[ch] = i;
        }
        
        vector<int>ans;
        int prev = -1;
        int mx = 0;
        
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            mx = max(mp[ch],mx);
            
            if(mx == i){
                ans.push_back(mx-prev);
                prev = mx;
            }
        }
        return ans;
    }
};