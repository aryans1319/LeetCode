// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
          int col0 = true;
        int rows = matrix.size();
        int cols = matrix[0].size();
        /*
        Converting the first row and first col of
        the matrix to dummy array, so that we don't 
        need to use any extra space for it
        
        Consider this case: 
      
        this col would be 0 as last element of first col
        is 0 but first row won't be 0 as whole if we change 
        every element to 0 of first col  0
                                         0
                                         0
                                         0
       it may happen that first row changes to 0 through the changed
       value which would give us wa, so we need to maintain a colcheck 
       variable to avoid this condition if colcheck is false this means 
       col (1st) is already set to 0
       
       traverse from rows=1 and check rest of the matrix if matrix[i][j]=0
       change dummy col and row to 0, if in the process if we have any 0
       inside the dummy col, we change colcheck to false
       \
        1 1 1 1
        
        1 0 1 1
        
        1 1 0 1
        
        0 0 0 1
        
        
        */
        for(int i = 0; i<rows ;i++){
            if(matrix[i][0] == 1) col0 = false;
            for(int j=1 ; j < cols; j++){
                if(matrix[i][j] == 1){
                    matrix[i][0] = 1; matrix[0][j] = 1;
                }
            } 
        }
        
        for(int i = rows-1; i>=0 ; i--){
            for(int j = cols-1; j>= 1; j--){
                if(matrix[i][0] == 1 || matrix[0][j] == 1){
                    matrix[i][j] = 1;
                }
            }
            if(col0 == false) matrix[i][0] = 1;
        }
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}


  // } Driver Code Ends