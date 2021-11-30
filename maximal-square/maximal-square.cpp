class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int area = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string,int>mp;
        for(int currentRow = 0 ; currentRow < m ; currentRow++){
            for(int currentCol = 0 ; currentCol < n ; currentCol++){
                if(matrix[currentRow][currentCol]=='1'){
                    int side = maxLength(matrix, currentRow, currentCol ,m,n,mp);
                    area = max(area, side*side);
                }
            }
        }
        return area;
    }
    
    int maxLength(vector<vector<char>> &grid,int currentRow, int currentCol,int m,int n,unordered_map<string,int>&mp){
        if(currentRow >= m || currentCol <0 || currentCol>=n || grid[currentRow][currentCol]=='0'){
            return 0;
        }   
        
        string currentKey = to_string(currentRow) + "_" + to_string(currentCol);
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
       
        int right = 1 + maxLength(grid , currentRow , currentCol+1 ,m,n,mp);
        int down = 1 + maxLength(grid ,currentRow+1, currentCol , m,n,mp);
        int drMove= 1 + maxLength(grid, currentRow + 1, currentCol+1 ,m,n,mp);
        
        mp[currentKey] = min({right,down,drMove});
        return    mp[currentKey]; 
    }
};