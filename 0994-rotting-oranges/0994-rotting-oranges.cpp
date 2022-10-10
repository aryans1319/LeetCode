class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        // queue = { {row, col}, time}
        queue<pair<pair<int,int>, int>>q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        int maxTime = 0;
        int del_row[4] = {-1, 0, +1, 0};
        int del_col[4] = {0, +1, 0, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            maxTime = max(time, maxTime);
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nrow = row + del_row[i];
                int ncol = col + del_col[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                    q.push({{nrow, ncol}, time + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] !=2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return maxTime;
    }
};