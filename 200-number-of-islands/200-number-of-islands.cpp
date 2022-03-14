class Solution {
public:
    void countIslands(vector<vector<char>>& grid,int currentRow,int currentCol,int m,int n){
        if(currentRow < 0 || currentRow>=m || currentCol < 0 || currentCol >=n || grid[currentRow][currentCol] == '0')
            return;
        
        grid[currentRow][currentCol] = '0';
        countIslands(grid,currentRow-1,currentCol,m,n);
        countIslands(grid,currentRow+1,currentCol,m,n);
        countIslands(grid,currentRow,currentCol-1,m,n);
        countIslands(grid,currentRow,currentCol+1,m,n);
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        for(int currentRow = 0;currentRow < m;currentRow++){
            for(int currentCol = 0;currentCol < n;currentCol++){
                if(grid[currentRow][currentCol] == '1'){
                    ans+=1;
                    countIslands(grid,currentRow,currentCol,m,n);
                }
            }
        }
        return ans;
    }
};