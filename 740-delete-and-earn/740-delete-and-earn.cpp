class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<int>freq(10001,0);
            int maxVal=INT_MIN;
                for(int num : nums)
                {
                        freq[num]++;
                        maxVal=max(maxVal,num);
                }
            unordered_map<int,int>mp;
            
            return solve(freq,0,mp);
    }
        int solve(vector<int>&freq,int cur,unordered_map<int,int>&mp)
        {
                if(cur>=freq.size())
                    return 0;
                
                int key = cur;
                if(mp.find(key)!=mp.end())
                    return mp[key];
                
                int dele = freq[cur]*cur + solve(freq,cur+2,mp);
                int notdel = solve(freq,cur+1,mp);
                
                mp[key]=max(dele,notdel);
        
                return mp[key];
        }
};