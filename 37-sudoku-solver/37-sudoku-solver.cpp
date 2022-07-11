class Solution {
public:
    
     bool isValidCell(vector<vector<char>>& board,int currentRow,int currentCol,int currentVal)
    {
        return isValidRow(board,currentRow,currentVal) && isValidCol(board, currentCol,currentVal) && isValidSubgrid(board,currentRow, currentCol,currentVal);
    }
    
     bool isValidRow(vector<vector<char>>& board,int currentRow,int currentVal)
    {
        for(int i=0;i<9;i++)
        {
            if(board[currentRow][i]== char(currentVal+'0'))
                return false;
        }
        return true;
    }
     bool isValidCol(vector<vector<char>>& board,int currentCol,int currentVal)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][currentCol]== char(currentVal+'0'))
                return false;
        }
        return true;
    }
    
    bool isValidSubgrid(vector<vector<char>>& board,int currentRow,int currentCol,int currentVal) 
        // need to find the starting point of every subgrid
    {
        int x = 3*(currentRow/3);
        int y = 3*(currentCol/3);
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[x+i][y+j]== char(currentVal+'0'))
                    return false;
            }
        }
        return true;
    }

    
    bool sudokuSolver(vector<vector<char>>& board, int currentRow, int currentCol, int n){
        
        if(currentRow == n){
            return true;
        }
        
        int nextRowIndex = -1;
        int nextColIndex = -1;
        
        if(currentCol != n-1){
            nextRowIndex = currentRow;
            nextColIndex = currentCol + 1;
        }
        else{
            nextRowIndex = currentRow + 1;
            nextColIndex = 0;
        }
        
        if(board[currentRow][currentCol] != '.'){
            return sudokuSolver(board,nextRowIndex,nextColIndex,n);
        }
        
        for(int currentVal = 1; currentVal<=9; currentVal++){
            if(isValidCell(board,currentRow,currentCol,currentVal)){
                board[currentRow][currentCol] = char(currentVal + '0');
            
            
            if(sudokuSolver(board,nextRowIndex,nextColIndex,n))
                return true;
             board[currentRow][currentCol] = '.';
        }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board,0,0,board.size());
        return;
    }
};