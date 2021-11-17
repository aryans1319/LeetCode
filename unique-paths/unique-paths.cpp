class Solution {
public:
    int uniquePaths(int m, int n) {
          int N = n+m-2; // total steps = n-1 + m-1
        int r = min(n,m) - 1; // will iterate on the minimum for efficiency = (total) C (min(right, down))
        
        double res = 1;
        
		// compute nCr
        for(int i=1; i<=r; ++i, N--){
            
            res = res * (N) / i;
        }
        
        return (int)res;
    }
};