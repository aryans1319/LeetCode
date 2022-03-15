class Solution {
public:
    
    int bfs(vector<vector<int>>& grid,int currentRow,int currentCol,int m,int n){
        queue<pair<int,int>>q;
        q.push({currentRow,currentCol});
        int ans = 0;
        while(!q.empty()){
            auto it = q.front();
            int curr_row = it.first;
            int curr_col = it.second;
            // grid[curr_row][curr_col] = 0;           
            q.pop();
            if(curr_row < 0 || curr_row>=m ||curr_col < 0 || curr_col >=n || grid[curr_row][curr_col] == 0){
            continue;
            }
            grid[curr_row][curr_col] = 0;
            ans++;
            q.push({curr_row-1,curr_col});
            q.push({curr_row,curr_col+1});
            q.push({curr_row+1,curr_col});
            q.push({curr_row,curr_col-1});
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        for(int currentRow = 0;currentRow < m;currentRow++){
            for(int currentCol = 0;currentCol < n;currentCol++){
                if(grid[currentRow][currentCol] == 1){
                    // ans+=1;
                   ans = max(ans,bfs(grid,currentRow,currentCol,m,n)) ;
                }
            }
        }
        return ans;
    }
};