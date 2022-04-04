class Solution {
public:
    int f(int i,int j,vector<vector<int>>&a,int n,vector<vector<int>>&dp){
        if(i == n-1) return a[n-1][j];
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int down = a[i][j] + f(i+1,j,a,n,dp);
        int diag = a[i][j] + f(i+1,j+1,a,n,dp);
        
        return dp[i][j] = min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();  
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,0,triangle,n,dp);
    }
};