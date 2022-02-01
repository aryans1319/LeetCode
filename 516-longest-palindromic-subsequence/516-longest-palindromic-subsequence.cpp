class Solution {
public:
    int longestPalindSubseqRec(vector<vector<int> >& dp, string& s, int i, int j) {
        if(i > j)
            return 0;
        // when one char
        if(i == j)
            return dp[i][j] = 1;
        
        if(dp[i][j] == -1) {
            if(s[i] == s[j])
                dp[i][j] = 2 + longestPalindSubseqRec(dp, s, i+1, j-1);
            else
                dp[i][j] = max(longestPalindSubseqRec(dp, s, i+1, j),
                               longestPalindSubseqRec(dp, s, i, j-1));
        }
        return dp[i][j];
    }
    
    // Recursive driver
    int longestPalindSubseqRecDriver(string& s) {
        if(s.empty())
                return 0;

        const int N = s.size();
        // dp(i, j): length of longest palindromic substring in s[i:j]
        vector<vector<int> > dp(N, vector<int>(N, -1)); 
        
        return longestPalindSubseqRec(dp, s, 0, N-1);
    }
    
    int longestPalindromeSubseq(string s) {
        return longestPalindSubseqRecDriver(s);
        //return longestPalindromeSubseqTabular(s);
    }
};