class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size();
        int res=0;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<accounts[i].size();j++){
                temp+=accounts[i][j];
            }
            res=max(temp,res);
        }
        return res;
    }
};