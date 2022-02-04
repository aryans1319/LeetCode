class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        for(int currentRow = 0;currentRow <m;currentRow++){
            for(int currentCol =0;currentCol < n;currentCol++){
                if(grid[currentRow][currentCol] == '1'){
                    ans+=1;
                    dfs(grid,currentRow,currentCol,m,n);
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<char>>& grid,int currentRow,int currentCol,int m,int n){
         if(currentRow < 0 || currentRow >=m || currentCol < 0 || currentCol >=n || grid[currentRow][currentCol] == '0'){
            return;
        }
        grid[currentRow][currentCol] = '0';
        
        dfs(grid,currentRow-1,currentCol,m,n);
         dfs(grid,currentRow+1,currentCol,m,n);
         dfs(grid,currentRow,currentCol-1,m,n);
         dfs(grid,currentRow,currentCol+1,m,n);
        
        return;
    }
};