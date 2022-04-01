class Solution {
public:
    int f(int i,int j,vector<vector<int>>&a,vector<vector<int>>&dp){
        if(i==0 && j==0) return a[0][0];
        if(i < 0 || j < 0) return 99999;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int up = a[i][j] + f(i-1,j,a,dp);
        int down = a[i][j] + f(i,j-1,a,dp);
        
        return dp[i][j] = min(up,down);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j] = grid[0][0];
                else{
                    int up = 99999;
                    int left = 99999;
                    if(i > 0) up = dp[i-1][j] + grid[i][j];
                    if(j > 0) left = dp[i][j-1] + grid[i][j];
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};