class Solution {
public:
    int dp[35];
    int f(int n){
         if(n==0 || n==1){
            return n;
         }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=f(n-1)+f(n-2);
        return dp[n];
    }
    
    int fib(int n) {
       memset(dp,-1,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        return f(n);
       
    }
};