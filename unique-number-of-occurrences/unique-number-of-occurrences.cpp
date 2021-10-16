class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        bool flag;
        set<int>s;
        for(auto i:arr){
            mp[i]++;
        }
        for(auto it:mp){
            s.insert(it.second);
            if(s.size()==mp.size())
                flag=true;
            else
                flag=false;
        }
     return flag;
    }
};