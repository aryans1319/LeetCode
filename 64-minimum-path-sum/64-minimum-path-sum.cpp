class Solution {
public:
    
    int getMinSum(vector<vector<int>> &grid, int currentIndexofI ,int currentIndexofJ, vector<vector<int>>&memo){        
        if(currentIndexofI > grid.size()-1 || currentIndexofJ > grid[0].size()-1)
        {
            return 99999;
        }
        
        
        if(currentIndexofI == grid.size()-1 && currentIndexofJ == grid[0].size()-1 ){
            return grid[currentIndexofI][currentIndexofJ];
        }
        
        if(memo[currentIndexofI][currentIndexofJ]!=-1)
            return memo[currentIndexofI][currentIndexofJ];
        
        
            int moveRight = getMinSum(grid, currentIndexofI , currentIndexofJ+1,memo )  + grid[currentIndexofI][currentIndexofJ];
            int moveDown = getMinSum(grid, currentIndexofI+1,currentIndexofJ,memo  )  + grid[currentIndexofI][currentIndexofJ];
            
            memo[currentIndexofI][currentIndexofJ] = min(moveDown,moveRight)  ;
                
             return memo[currentIndexofI][currentIndexofJ];
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
         vector<vector<int>> memo(m,vector<int>(n, -1));
        return getMinSum(grid,0,0,memo);
    }
};