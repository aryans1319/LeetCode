class Solution {
public:
     static bool comparator(pair<string,int> p1, pair<string,int> p2)
    {
        if(p1.second>p2.second || (p1.second==p2.second && p1.first<p2.first))
            return true;
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(int i =0; i < words.size(); i++){
            mp[words[i]]++;
        }
        vector<pair<string,int>>mapped;
        for(auto i: mp){
            mapped.push_back({i.first, i.second});
        }
        sort(mapped.begin(), mapped.end(), comparator);
        vector<string>ans;
        for(auto i : mapped){
            ans.push_back(i.first);
            k--;
            if(k==0) break;
        }
        return ans;
    }
};