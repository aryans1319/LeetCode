class Solution {
public:
    int mod = 1e9+7;
    int totalNoWays(int m,int n,int maxMove,int startRow,int startCol,unordered_map<string,int>&mp){
        if(startRow<0 || startCol <0 || startRow > m-1 || startCol > n-1){
            return 1;
        }
        
        if(maxMove <= 0){
            return 0;
        }
        
        string currentKey = to_string(maxMove)+"_"+to_string(startRow)+"_"+to_string(startCol);
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        long long left = totalNoWays(m,n,maxMove-1,startRow,startCol-1,mp)%mod;
        long long right = totalNoWays(m,n,maxMove-1,startRow,startCol+1,mp)%mod;
        long long down= totalNoWays(m,n,maxMove-1,startRow-1,startCol,mp)%mod;
        long long up = totalNoWays(m,n,maxMove-1,startRow+1,startCol,mp)%mod;
        mp[currentKey] = (left+right+down+up)%mod;
        return mp[currentKey]; 
        
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        unordered_map<string,int>mp;
        return totalNoWays(m,n,maxMove,startRow,startColumn,mp)%mod;
    }
};