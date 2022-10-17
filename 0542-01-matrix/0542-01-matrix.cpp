class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> visitedMatrix(n, vector<int>(m, 0));
        vector<vector<int>> distanceMatrix(n, vector<int>(m, 0));
        queue<pair<pair<int,int>, int >> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    visitedMatrix[i][j] = 1;
                }
                else{
                    visitedMatrix[i][j] = 0;
                }
            }
        }
        
        int del_row[] = {-1, 0, +1, 0};
        int del_col[] = {0, +1, 0, -1};
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            
            int steps = q.front().second;
            q.pop();
            
            distanceMatrix[row][col] = steps;
            
            for(int i = 0; i < 4; i++){
                int nrow = row + del_row[i];
                int ncol = col + del_col[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                   && visitedMatrix[nrow][ncol] == 0) {
                    visitedMatrix[nrow][ncol] = 1;  
                    q.push({ {nrow, ncol}, steps + 1 });
                }
            }
        }
        return distanceMatrix;
    }
};

// TC : O(N*M*4);
// SC : O(N*M) + O(N*M) + O(n) ~ O(N x M)