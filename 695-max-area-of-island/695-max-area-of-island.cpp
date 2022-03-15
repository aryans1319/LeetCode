class Solution {
public:
     int countIslands(vector<vector<int>>& grid,int currentRow,int currentCol,int m,int n){
        if(currentRow < 0 || currentRow>=m || currentCol < 0 || currentCol >=n || grid[currentRow][currentCol] == 0)
            return 0;
        
        grid[currentRow][currentCol] = 0;
        int a = countIslands(grid,currentRow-1,currentCol,m,n);
        int b =countIslands(grid,currentRow+1,currentCol,m,n);
        int c =countIslands(grid,currentRow,currentCol-1,m,n);
        int d =countIslands(grid,currentRow,currentCol+1,m,n);
        
        return 1 + a+b+c+d;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        for(int currentRow = 0;currentRow < m;currentRow++){
            for(int currentCol = 0;currentCol < n;currentCol++){
                if(grid[currentRow][currentCol] == 1){
                    // ans+=1;
                    ans = max(ans,countIslands(grid,currentRow,currentCol,m,n));
                }
            }
        }
        return ans;
    }
};