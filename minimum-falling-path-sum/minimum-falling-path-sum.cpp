class Solution {
public:
     int largestSum(int i,int j, vector<vector<int>> &Matrix,int N,unordered_map<string,int>&mp){
        if( i<0 || i >= N || j>=N || j<0){
            return 100001;
        }
        
        if(i == N-1){
            return Matrix[i][j];
        }
        
        string currentKey = to_string(i) + "_" + to_string(j);
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        int down = largestSum(i+1,j,Matrix,N,mp) + Matrix[i][j];
        int diagonallyLeft = largestSum(i+1,j-1,Matrix,N,mp)+ Matrix[i][j];
        int diagonallyRight = largestSum(i+1,j+1,Matrix,N,mp)+ Matrix[i][j];
        
        mp[currentKey] = min({down,diagonallyLeft, diagonallyRight});
        
        return mp[currentKey];
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int N = matrix.size();
        unordered_map<string,int>mp;
        int ans=INT_MAX;
        for(int j=0;j<N;j++){
            int tempAns = largestSum(0,j,matrix,N,mp);
            ans = min(tempAns,ans);
        }
        return ans;
    }
};