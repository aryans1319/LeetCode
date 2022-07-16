class Solution {
public:
    int totalNQueens(int n) {
        int ans[1] = {0};
        vector<vector<char>>board(n,vector<char>(n,'.'));
        nQueens(board,0,n,ans);
        return ans[0];
    }
     private:
        void nQueens(vector<vector<char>>&board, int currentRow,int n,int ans[]){
            if(currentRow == n){
                ans[0] +=1;
                return;
            }
            for(int currentCol = 0; currentCol < n; currentCol++){
                /* 
                iterate in the col and check if its a valid cell or not
                if it's a valid cell place the queen, move to next row
                and undo the change
                */
                if(isValid(board,currentRow,currentCol,n)){
                    board[currentRow][currentCol] = 'Q';
                    nQueens(board,currentRow+1,n,ans);
                    board[currentRow][currentCol] = '.';
                }
            
        }
        }
    
    private:
    bool isValid(vector<vector<char>>&board, int currentRow, int currentCol,int n){
        return isRowValid(board,currentRow,n) && isColValid(board,currentCol,n) &&
               isDiagonalValid(board,currentRow,currentCol,n); 
    }
    bool isRowValid(vector<vector<char>>&board,int currentRow, int n){
        for(int currentCol = 0 ;currentCol < n; currentCol++){
            if(board[currentRow][currentCol] == 'Q')
                return false;
        }
        return true;
    }
    bool isColValid(vector<vector<char>>&board,int currentCol, int n){
        for(int currentRow = 0 ;currentRow < n; currentRow++){
            if(board[currentRow][currentCol] == 'Q')
                return false;
        }
        return true;
    }
    bool isDiagonalValid(vector<vector<char>>&board,int currentRow,int currentCol, int n){
        //leftUpDiagonal
        int x = currentRow;
        int y = currentCol;
        
        while(x>=0 && y>=0){
            if(board[x][y] == 'Q')
                return false;
            
            x-=1;
            y-=1;
        }
        
        //rightUpDiagonal
        x = currentRow;
        y = currentCol;
        
        while(x>=0 && y <n){
            if(board[x][y] == 'Q')
                return false;
            
            x-=1;
            y+=1;
        }
       return true; 
      }
};