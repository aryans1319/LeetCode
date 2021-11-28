class Solution {
public:
    int totalPaths(vector<vector<int>>& obstacleGrid, int  i , int j, int m , int n,unordered_map<string,int>&mp){
        if( i>= m || j>=n ){
            return 0;
        }
        
        if(obstacleGrid[i][j]==1 ){
            return 0;
        }
         
        
        if(i==m-1 && j==n-1){
            return 1;
        }
        
        string currentKey = to_string(i)+ "_" + to_string(j);
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        int moveRight = totalPaths(obstacleGrid, i,j+1,m,n,mp);
        int moveDown = totalPaths(obstacleGrid,i+1,j,m,n,mp);
        
        mp[currentKey] = moveRight+moveDown;
        
        return  mp[currentKey];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        unordered_map<string,int>mp;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return totalPaths(obstacleGrid,0,0,m,n,mp);
    }
};