class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minH;
        for(auto i : mp){
            minH.push({i.second,i.first});
            if(minH.size() > k){
                minH.pop();
            }
        }
        while(minH.size() > 0){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }
};