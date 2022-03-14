class Solution {
public:
    void bfs(vector<vector<char>>& grid,int currentRow,int currentCol,int m,int n){
        queue<pair<int,int>>q;
        q.push({currentRow,currentCol});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            int dx [] = {1,-1,0,0};
            int dy [] = {0,0,-1,1};
            
            for(int currentDir = 0;currentDir<4;currentDir++){
                int curr_row = row + dx[currentDir];
                int curr_col = col + dy[currentDir];
                if(curr_row < 0 || curr_row>=m ||curr_col < 0 || curr_col >=n || grid[curr_row][curr_col] == '0'){
                    continue;
                }
                q.push({curr_row,curr_col});
                grid[curr_row][curr_col] = '0';

            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        for(int currentRow = 0;currentRow < m;currentRow++){
            for(int currentCol = 0;currentCol < n;currentCol++){
                if(grid[currentRow][currentCol] == '1'){
                    ans+=1;
                    bfs(grid,currentRow,currentCol,m,n);
                }
            }
        }
        return ans;
    }
};