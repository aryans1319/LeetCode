class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int>mp,mp1;
        // int ans=-1;
        for(int i=0;i<trust.size();i++){
            mp[trust[i][0]]++;
            mp1[trust[i][1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(mp[i]==0 and mp1[i] == n-1 )
                return i;
        }
        return -1;
    }
};