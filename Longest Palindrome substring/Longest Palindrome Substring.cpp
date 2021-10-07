class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string p = s;
        reverse(p.begin(), p.end());
        
        int dp[n+1][n+1];
        
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        
        int maxi = 0;
        int a, b;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==p[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(maxi<dp[i][j]){
                        
                        /*now just check that the substring we got is pallindrome or not
                        by reversing it and equating */
                        string temp = s.substr(i-dp[i][j], dp[i][j]);
                        string rev_temp = temp;
                        
                        reverse(rev_temp.begin(), rev_temp.end());
                        
                        //if pallindrome then only store
                        if(temp==rev_temp){
                            maxi = dp[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        string out;
        
        while(a>0 && b>0 && dp[a][b]>0){
            out.push_back(s[a-1]);
            a--;
            b--;
        }
        
        return out;
    }
};
