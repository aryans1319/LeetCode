class Solution {
public:
    void dfs(vector<vector<char>>&board,int currentRow,int currentCol,int row,int col)
    {
        if(currentRow < 0 || currentRow >= row || currentCol < 0 || currentCol >= col || board[currentRow][currentCol] != 'O'){
            return ;
        }
        
        board[currentRow][currentCol] = '1';
        dfs(board,currentRow-1,currentCol,row,col);
        dfs(board,currentRow+1,currentCol,row,col);
        dfs(board,currentRow,currentCol-1,row,col);
        dfs(board,currentRow,currentCol+1,row,col);
    }
    
    
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        if(row==0) return;
        
        for(int i=0;i<row;i++){
            if(board[i][0] == 'O'){
                dfs(board,i,0,row,col);
            }  
            if(board[i][col-1] == 'O'){
                dfs(board,i,col-1,row,col);
            }
        }
        
         for(int j=0;j<col;j++){
            if(board[0][j] == 'O'){
                dfs(board,0,j,row,col);
            }  
            if(board[row-1][j] == 'O'){
                dfs(board,row-1,j,row,col);
            }
        }
       for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               if(board[i][j] == 'O'){
                   board[i][j] = 'X';
               }
               if(board[i][j] == '1'){
                   board[i][j] = 'O';
               }
           }
       } 
    }
};