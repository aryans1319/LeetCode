class Solution {
public:
    int dp[20];
    
    int numTrees(int n) {
       memset(dp,-1,sizeof(dp)) ;
    // unordered_map<int,int>mp;
        return nthCatalan(n);
    }
    int nthCatalan(int n){
        if(n<=1){
            return 1;
        }
       
        if(dp[n]!=-1){
            return dp[n];
        }
        // int currentKey = n;
        // if(mp.find(currentKey)!=mp.end()){
        //     mp[currentKey];
        // }
        int ways=0;
        for(int i=0;i<n;i++){
            ways+= nthCatalan(i)*nthCatalan(n-i-1);
        }
        dp[n]=ways;
        return dp[n];
    }
};