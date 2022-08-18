class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size()/2;
        unordered_map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }
        vector<int>v;
        for(auto it:mp){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        int ans=0;
        int sum=0;
        while(sum<n)
        {
            sum+=v.back();
            v.pop_back();
            ans++;
        }
        return ans;
    }
};