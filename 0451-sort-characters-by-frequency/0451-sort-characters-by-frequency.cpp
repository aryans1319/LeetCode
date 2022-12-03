class Solution {
public:
       static bool cmp(pair<char,int>&a, pair<char,int>&b)
    {
        return a.second > b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto i: s){
            mp[i]++;
        }
        string ans="";
        vector<pair<char,int>>v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),cmp);
        for(auto c: v){
            while(c.second>0){
                ans+=c.first;
                c.second--;
            }
        }
        return ans;
    }
};