class Solution {
private:
    bool isValid(int x, int y, int m, int n, vector <vector <int>>&grid, vector <vector <int>>&visited){
        if(visited[x][y] or grid[x][y]) return false;
        return true;
    }
    bool dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>&grid) {
        if(!isValid(row, col, grid.size(), grid[0].size(), grid, vis)) return true; 
        
        if(row == grid.size()-1 || row == 0 || col == grid[0].size()-1 || col == 0){
              return false;
        }   
        vis[row][col] = 1;
        bool left = dfs(row, col - 1, vis, grid);
        bool right = dfs(row, col + 1, vis, grid);
        bool down = dfs(row + 1, col, vis, grid);
        bool up = dfs(row - 1, col, vis, grid);
        return left && right && down && up;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    if(dfs(i,j,vis,grid)){
                        islands++;
                    }
                }
            }
        }
        return islands;
    }
};