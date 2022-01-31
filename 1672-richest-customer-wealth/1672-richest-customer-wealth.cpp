class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = INT_MIN;
        // vector<int>ans;
        for(int i=0;i<accounts.size();i++){
               int sum=0;
            for(int j=0;j<accounts[0].size();j++){
                sum+=accounts[i][j];
            }
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};