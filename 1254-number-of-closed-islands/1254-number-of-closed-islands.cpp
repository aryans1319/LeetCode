class Solution {
public:
     bool dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>&grid, int del_row[], int del_col[]) {
        if(vis[row][col]) return 1;
        vis[row][col] = 1;
        bool isClosed = true;
        for(int i = 0; i < 4; i++){
            int nrow = row + del_row[i];
            int ncol = col + del_col[i];
            
            if(nrow >=0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == 0 && vis[nrow][ncol] == 0){
                if(nrow == 0 || nrow == grid.size() - 1 || ncol == 0 || ncol == grid[0].size() - 1){
                    isClosed = false;
                }
                else{
                    isClosed = dfs(nrow, ncol, vis, grid,del_row, del_col) && isClosed;
                }
            }
        } 
        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        int del_row[4] = {-1,0,+1,0};
        int del_col[4] = {0,1,0,-1};
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i = 1; i < n-1; i++){
            for(int j = 1; j < m-1; j++){
                if(!vis[i][j] && grid[i][j] == 0 && dfs(i,j,vis,grid,del_row,del_col)){
                        islands++;
                }
            }
        }
        return islands;
    }
};