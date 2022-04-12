class Solution {
public:
    bool isval(int x,int y,vector<vector<int>>& board )
{
    return (x>=0&&x<board.size() && y>=0&&y<board[0].size());
}

void gameOfLife(vector<vector<int>>& board) {
    
     int m = board.size();
    int n = board[0].size();
    
    vector<int> x = {0,1,1,1,-1,-1,-1,0};
    vector<int> y = {-1,1,-1,0,0,1,-1,1};
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            
        {
            int c = 0;
            // counting the next live neighbour for each grid
            for(int k=0; k<8; k++)
            {
            int cx = i+x[k];
            int cy = j+y[k];
            if(isval(cx,cy,board)&&abs(board[cx][cy])==1)
                c++;
            }
            
            if(board[i][j]==1&&(c<2||c>3))
                board[i][j]=-1;
            
            if(board[i][j]==0&&c==3)
                board[i][j]=2;
                
                   
        }
        
    }
    
 for(int i=0;i<m;i++)
    {
       for(int j=0;j<n;j++)
            
        {
           if(board[i][j]>=1)
               board[i][j]=1;
           else
               board[i][j]=0;
               
               
        }
    
    
}
 
   

    
}
};