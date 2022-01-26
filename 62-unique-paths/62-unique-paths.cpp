class Solution {
public:
    int totalPaths(int  i , int j, int m , int n,unordered_map<string,int>&mp){
        if( i>= m || j>=n ){
            return 0;
        }
        
        if(i==m-1 && j==n-1){
            return 1;
        }
        
        string currentKey = to_string(i)+ "_" + to_string(j);
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        int moveRight = totalPaths(i,j+1,m,n,mp);
        int moveDown = totalPaths(i+1,j,m,n,mp);
        
        mp[currentKey] = moveRight+moveDown;
        
        return  mp[currentKey];
    }
    
    
    int uniquePaths(int m, int n) {
        unordered_map<string,int>mp;
      return totalPaths(0,0,m,n,mp);
    }
};